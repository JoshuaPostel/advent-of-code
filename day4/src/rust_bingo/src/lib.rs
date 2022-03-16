#[cxx::bridge]
mod ffi {

    struct Bingo {
        board: [[u8; 5]; 5],
        marked: [[bool; 5]; 5],
    }

    extern "Rust" {
        // if the mark results in a bingo, return SCORE otherwise return zero
        fn mark(self: &mut Bingo, number: u8) -> i32;
        fn print(self: &Bingo);
    }

    unsafe extern "C++" {
        include!("day4.h");
        fn score(self: &Bingo, just_called: i32) -> i32;
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
            self.score(number.into())
        } else {
            0
        }
    }

    pub fn print(&self) {
        for (i, row) in self.board.iter().enumerate() {
            let mut text = String::from("");
            for (j, element) in row.iter().enumerate() {
                if self.marked[i][j] {
                    text.push('x');
                } else {
                    text.push('o');
                }
                text.push_str(&element.to_string());
                text.push(' ');
                if element < &10 {
                    text.push(' ');
                }
            }
            println!("{}", text);
        }
    }

    fn has_bingo(&self) -> bool {
        //println!("checking for bingo");
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
