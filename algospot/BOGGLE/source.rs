use std::io;

fn read_integer() -> i32 {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("failed to read a line");
    buf.trim().parse::<i32>().expect(&format!("failed to read an integer from: {}", buf))
}

fn read_string() -> String {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("failed to read a line");
    buf.trim().to_string()
}

fn is_connected(i: &i8, j: &i8, dynamic: &[[bool; 5]; 5]) -> bool {
    for ii in i - 1 .. i + 2 {
        for jj in j - 1 .. j + 2 {
            if ii == *i && jj == *j {
                continue;
            } else if ii < 0 || jj < 0 {
                continue;
            } else if ii >= 5 || jj >= 5 {
                continue;
            }

            if dynamic[ii as usize][jj as usize] {
                return true;
            }
        }
    }

    false
}

fn has_word(board: &[[char; 5]; 5], word: &str) -> bool {
    assert!(word.len() <= 10, "{}", word);

    let mut dynamic = [[[false; 5]; 5]; 10];

    for (k, ch) in word.chars().enumerate() {
        for i in 0..5 {
            for j in 0..5 {
                if board[i][j] != ch {
                    continue;
                }

                let found = {
                    if k == 0 {
                        true
                    } else {
                        is_connected(&(i as i8), &(j as i8), &dynamic[k - 1])
                    }
                };
                
                if found {
                    dynamic[k][i][j] = true;
                    if k + 1 == word.len() {
                        return true;
                    }
                }
            }
        }
    }

    false
}

fn solve() {
    let mut board = [['a'; 5]; 5];

    for i in 0..5 {
        let string = read_string();
        assert_eq!(string.len(), 5);
        for (j, ch) in string.chars().enumerate() {
            board[i][j] = ch;
        }
    }

    let num_of_words = read_integer();
    for _i in 0..num_of_words {
        let word = read_string();
        match has_word(&board, &word) {
            true => println!("{} YES", word),
            false => println!("{} NO", word),
        }
    }
}

fn main() {
    let mut testcases = read_integer();
    while testcases > 0 {
        solve();
        testcases -= 1;
    }
}
