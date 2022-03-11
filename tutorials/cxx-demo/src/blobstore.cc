#include "cxx-demo/include/blobstore.h"
#include "cxx-demo/src/main.rs.h"
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <unordered_map>

class BlobstoreClient::impl {
  friend BlobstoreClient;
  using Blob = struct {
    std::string data;
    std::set<std::string> tags;
  };
  std::unordered_map<uint64_t, Blob> blobs;
};

BlobstoreClient::BlobstoreClient() : impl(new class BlobstoreClient::impl) {}

uint64_t BlobstoreClient::put(MultiBuf &buf) const {
  std::string contents;
  while (true) {
    auto chunk = next_chunk(buf);
    if (chunk.size() == 0) {
      break;
    }
    contents.append(reinterpret_cast<const char *>(chunk.data()), chunk.size());
  }

  auto blobid = std::hash<std::string>{}(contents);
  return blobid;
}

void BlobstoreClient::tag(uint64_t blobid, rust::Str tag) const {
   impl->blobs[blobid].tags.emplace(tag);
}

BlobMetadata BlobstoreClient::metadata(uint64_t blobid) const {
  BlobMetadata metadata{};
  auto blob = impl->blobs.find(blobid);
  if (blob != impl->blobs.end()) {
    metadata.size = blob->second.data.size();
    std::for_each(blob->second.tags.cbegin(), blob->second.tags.cend(),
      [&](auto &t) { metadata.tags.emplace_back(t); });
  }
  return metadata;
}

std::unique_ptr<BlobstoreClient> new_blobstore_client() {
  return std::unique_ptr<BlobstoreClient>(new BlobstoreClient());
}
