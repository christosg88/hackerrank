pub fn maximize_xor(l: u32, r: u32) -> u32 {
    let mut max = 0;
    for a in l..r {
        for b in a+1..r+1 {
            let x = a ^ b;
            if x > max {
                max = x;
            }
        }
    }
    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(maximize_xor(10, 15), 7);
    }
    #[test]
    fn test_2() {
        assert_eq!(maximize_xor(5, 6), 3);
    }
}
