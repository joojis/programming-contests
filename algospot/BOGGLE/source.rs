use std::io;

fn read_integer() -> i32 {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf);
    buf.trim().parse::<i32>().expect(&format!("failed to read an integer from: {}", buf))
}

fn read_string() -> String {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf);
    buf.trim().to_string()
}

// TODO
fn has_word(board: &[[char; 5]; 5], word: &str) -> bool {
    assert!(word.len() <= 10, "{}", word);

    let mut dynamic = [[[false; 10]; 5]; 5];

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
                        let mut ret = false;
                        for ii in i - 1 .. i + 1 {
                            for jj in j - 1 .. j + 1 {
                                if ii < 0 || jj < 0 || ii >= 5 || jj >= 5 {
                                    continue;
                                } else if ii == i && jj == j {
                                    continue;
                                }

                                // println!("dynamic[{}][{}][{}] == {}", ii, jj, k, dynamic[ii][jj][k - 1]);
                                if (ch == 'R') {
                                    println!("ii = {} jj = {}", ii, jj);
                                }
                                if dynamic[ii][jj][k - 1] == true {
                                    ret = true;
                                }
                            }
                        }
                        ret
                    }
                };
                
                
                // println!("found={} k={} len={}", found, k, word.len());
                if found {
                    dynamic[i][j][k] = true;
                    if k + 1 == word.len() {
                        return true;
                    }
                }
            }
        }

        println!("word ={} k == {}", word, k);
        for i in 0..5 {
            for j in 0..5 {
                print!("{} ", dynamic[i][j][k]);
            }
            println!("");
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
    for i in 0..num_of_words {
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
