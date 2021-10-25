#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

int main()
{
    std::map<uint64_t, std::map<uint64_t, uint64_t>> mp{};
    std::map<uint64_t, std::set<uint64_t>> keys2{};
    std::set<uint64_t> keys{};
    uint32_t R, C, V;
    while (std::cin >> R >> C >> V) {
        if (R == 0 && C == 0 && V == 4294967161) {
            break;
        }
        mp[(uint64_t)R][(uint64_t)C] = (uint64_t)V;
        keys.insert((uint64_t)R);
        keys2[(uint64_t)R].insert((uint64_t)C);
    }
    while (std::cin >> R >> C >> V) {
        keys.insert((uint64_t)R);
        keys2[(uint64_t)R].insert((uint64_t)C);
        mp[R][C] = ((uint64_t)V + mp[R][C]) % 4294967161;
    }
    for (auto i : keys) {
        for (auto j : keys2[i]) {
            if (mp[i][j] != 0) {
                std::cout << i << ' ' << j << ' ' << mp[i][j] << std::endl;
            }
        }
    }
    return 0;
}
