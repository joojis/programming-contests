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
fn has_word() -> bool {
    false
}

fn solve() {
    let mut board: Vec<String> = vec![];

    for i in 0..5 {
        board.push(read_string());
    }
    println!("{:?}", board);

    let num_of_words = read_integer();
    for i in 0..num_of_words {
        let word = read_string();
        match has_word() {
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
