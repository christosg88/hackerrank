// https://www.hackerrank.com/challenges/counter-game
use std::io;

use counter_game::num_steps_till_one;

fn main() {
    let mut num_testcases = String::new();
    io::stdin().read_line(&mut num_testcases).unwrap();
    let num_testcases: u32 = num_testcases.trim().parse().unwrap();

    let mut counters: Vec<u64> = Vec::new();

    let mut counter = String::new();
    for _i in 0..num_testcases {
        io::stdin().read_line(&mut counter).unwrap();
        counters.push(counter.trim().parse().unwrap());
        counter.clear();
    }
    for &counter in counters.iter() {
        if num_steps_till_one(counter) % 2 == 0 {
            println!("Richard");
        } else {
            println!("Louise");
        }
    }
}
