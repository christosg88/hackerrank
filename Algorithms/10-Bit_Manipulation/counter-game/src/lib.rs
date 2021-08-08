pub fn num_steps_till_one(mut counter: u64) -> u64 {
    if counter <= 1 {
        return 0;
    } else {
        let mut num_steps = 0;
        // consume all zeros until the least significant 1
        // these would all be division by 2, so add 1 to the number of steps
        while counter != 0 && counter & 1 == 0 {
            num_steps += 1;
            counter >>= 1;
        }
        // we can right-shift one more time since we want to reach 1 instead of 0
        counter >>= 1;
        // now for each bit that is a 1, add 1 to the number of steps, because we would need to
        // subtract the maximum power of two that is less than the number
        while counter != 0 {
            num_steps += counter & 1;
            counter >>= 1;
        }
        return num_steps;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(num_steps_till_one(1), 0);
    }

    #[test]
    fn test_2() {
        assert_eq!(num_steps_till_one(2), 1);
    }

    #[test]
    fn test_3() {
        assert_eq!(num_steps_till_one(4), 2);
    }

    #[test]
    fn test_4() {
        assert_eq!(num_steps_till_one(132), 3);
    }

    #[test]
    fn test_5() {
        assert_eq!(num_steps_till_one(6), 2);
    }

    #[test]
    fn test_6() {
        assert_eq!(num_steps_till_one(1560834904), 16);
    }

    #[test]
    fn test_7() {
        assert_eq!(num_steps_till_one(1768820483), 14);
    }

    #[test]
    fn test_8() {
        assert_eq!(num_steps_till_one(1533726144), 21);
    }

    #[test]
    fn test_9() {
        assert_eq!(num_steps_till_one(1620434450), 14);
    }

    #[test]
    fn test_10() {
        assert_eq!(num_steps_till_one(1463674015), 19);
    }
}
