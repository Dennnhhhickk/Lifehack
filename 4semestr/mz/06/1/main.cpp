#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

int main()
{
    int32_t w1, w2;
    uint32_t a;
    uint64_t L = 0, D = 0;
    double W = 0;
    std::cin >> w1 >> w2;
    while (std::cin >> a) {
        for (int i = 0; i < 32; ++i) {
            if (a % 2) {
                ++L;
            } else {
                ++D;
            }
            a /= 2;
        }
        W += 32;
    }
    uint64_t L1 = L - std::min(L, (uint64_t)w2);
    uint64_t D1 = D - std::min(D, (uint64_t)w1);
    std::cout << std::setprecision(10) << -1 + 2 * (L1) / W << ' '
            << -1 + 2 * (W - D1) / W << std::endl;
    return 0;
}
