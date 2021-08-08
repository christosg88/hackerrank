// https://www.hackerrank.com/challenges/maximizing-xor
use std::io;

use maximizing_xor::maximize_xor;

fn main() {
    let mut a = String::new();
    let mut b = String::new();

    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();

    let a: u32 = a.trim().parse().unwrap();
    let b: u32 = b.trim().parse().unwrap();

    println!("{}", maximize_xor(a, b));
}
