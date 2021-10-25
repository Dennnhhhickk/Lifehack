#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    int n, m, a1, a2, b1, b2;
    std::cin >> n >> m;
    while (std::cin >> a1 >> a2 >> b1 >> b2) {
        std::cout << std::min(std::abs(a1 - b1), (m - std::max(a1, b1)) +
                std::min(a1, b1)) + std::min(std::abs(a2 - b2),
                (n - std::max(a2, b2)) + std::min(a2, b2)) << std::endl;
    }
    return 0;
}
