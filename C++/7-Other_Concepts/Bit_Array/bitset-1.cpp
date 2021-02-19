#include <iostream>
#include <limits>

inline uint32_t get_next(const uint32_t &current, const uint32_t &P, const uint32_t &Q, const uint32_t &limit) {
    return (current * P + Q) & limit;
}

/**
 * A slight variation of Brent's algorithm
 * (https://en.wikipedia.org/wiki/Cycle_detection#Brent.27s_algorithm)
 * @param  N     the most number of steps
 * @param  S     implementation dependent
 * @param  P     implementation dependent
 * @param  Q     implementation dependent
 * @param  limit implementation dependent
 * @return       all unique numbers that are traversed
 */
unsigned int brent(uint32_t N, uint32_t S, uint32_t P, uint32_t Q, uint32_t limit) {
    uint32_t power, lam;
    power = lam = 1;
    uint32_t tortoise = S;
    uint32_t hare = get_next(tortoise, P, Q, limit);
    uint32_t hare_steps = 1;

    while (tortoise != hare && hare_steps < N) {
        if (power == lam) {
            tortoise = hare;
            power <<= 1u;
            lam = 0;
        }

        uint32_t old_hare = hare;
        hare = get_next(hare, P, Q, limit);
        if (hare != old_hare) {
            hare_steps++;
        }
        else {
            return hare_steps + 1;
        }
        lam++;
    }

    return hare_steps;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    uint32_t limit = std::numeric_limits<uint32_t>::max() >> 1u;
    uint32_t N, S, P, Q;
    std::cin >> N >> S >> P >> Q;

    std::cout << brent(N, S, P, Q, limit) << '\n';

    return 0;
}
