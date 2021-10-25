#include <iostream>
#include <cstdint>
#include <ios>
#include <string>

enum { BASE = 16, BITS = 4, BIAS  = 10, NUM_PER_STR = 4};

uint32_t str_to_int(std::string a, int base)
{
    uint32_t res = 0;
    for (size_t i = 0; i < a.size(); i++) {
        res *= base;
        if (isdigit(a[i])) {
            res += int(a[i] - '0');
        } else {
            res += int(a[i] - 'a') + BIAS;
        }
    }
    return res;
}

uint64_t read_bits(int bits)
{
    std::string s;
    uint64_t res = 0;
    for (int i = 0; i < bits; i++) {
        if (!(std::cin >> s)) {
            return uint64_t(-1);
        }
        res = res * BASE * BASE + str_to_int(s, BASE);
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    uint64_t k = 0, a;
    std::string s;
    while (!(std::cin.eof())) {
        if (k == 0) {
            std::cin >> s;
        }
        k = (k + 1) % NUM_PER_STR;
        a = read_bits(BITS);
        if (a != uint64_t(-1)) {
            std::cout << a << std::endl;
        }
    }

    return 0;
}
