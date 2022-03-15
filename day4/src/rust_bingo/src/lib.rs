use cxx::let_cxx_string;

#[cxx::bridge]
mod ffi {

    struct Bingo {
        board: [[u8; 5]; 5],
        marked: [[bool; 5]; 5],
    }

    extern "Rust" {
        //type Bingo;
        // if the mark results in a bingo, return SCORE otherwise return zero
        fn mark(self: &mut Bingo, number: u8) -> i32;
        fn print(self: &Bingo);

        fn plus_one(val: i32) -> i32;
        fn times_two(val: i32) -> i32;
    }

    unsafe extern "C++" {
        include!("day4.h");

        //fn new(file_path: String) -> Bingo;

        fn plus_two(val: i32) -> i32;

        fn new_board() -> Bingo;
        fn score(self: &Bingo) -> i32;
    }
}

impl ffi::Bingo {
    pub fn mark(&mut self, number: u8) -> i32 {
        for (i, row) in self.board.iter().enumerate() {
            for (j, element) in row.iter().enumerate() {
                if element == &number {
                    self.marked[i][j] = true;
                }
            }
        }
        if self.has_bingo() {
            self.score()
        } else {
            0
        }
    }

    pub fn print(&self) {
        for (i, row) in self.board.iter().enumerate() {
            let mut text = String::from("");
            for (j, element) in row.iter().enumerate() {
                text.push_str(&element.to_string());
                if self.marked[i][j] {
                    text.push('X');
                } else {
                    text.push('O');
                }
                text.push(' ');
                if &10 <= element {
                    text.push(' ');
                }
            }
            println!("{}", text);
        }
    }

    fn has_bingo(&self) -> bool {
        println!("checking for bingo");
        for row in self.marked.iter() {
            if row.iter().all(|x| *x) {
                return true;
            }
        }
        for column in 0..5 {
            if self.marked[0][column]
                && self.marked[1][column]
                && self.marked[2][column]
                && self.marked[3][column]
                && self.marked[4][column]
            {
                return true;
            }
        }
        false
    }
}

fn times_two(val: i32) -> i32 {
    let mut result = 0;
    for _ in 0..val {
        result = ffi::plus_two(result);
    }
    result
}

fn plus_one(val: i32) -> i32 {
    val + 1
}
