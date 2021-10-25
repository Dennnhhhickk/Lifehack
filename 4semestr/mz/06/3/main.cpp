#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

int main()
{
    std::map<uint64_t, std::map<uint64_t, uint64_t>> mp{};
    std::map<uint64_t, std::map<uint64_t, uint64_t>> mp1{};
    std::map<uint64_t, std::map<uint64_t, uint64_t>> mp3{};
    std::map<uint64_t, std::set<uint64_t>> keys2{};
    std::map<uint64_t, std::set<uint64_t>> keys21{};
    std::map<uint64_t, std::set<uint64_t>> keys23{};
    std::set<uint64_t> keys{};
    std::set<uint64_t> keys1{};
    std::set<uint64_t> keys3{};
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
        mp1[(uint64_t)R][(uint64_t)C] = (uint64_t)V;
        keys1.insert((uint64_t)R);
        keys21[(uint64_t)R].insert((uint64_t)C);
    }
    uint64_t ans = 0;
    for (auto R1 : keys1) {
        for (auto C1 : keys21[R1]) {
            for (auto i : keys) {
                ans = 0;
                for (auto j : keys2[i]) {
                    ans = (ans + ((mp[i][j] % 4294967161) * (mp1[j][C1] % 4294967161))% 4294967161) % 4294967161;
                }
                keys3.insert((uint64_t)i);
                keys23[(uint64_t)R1].insert(C1);
                mp3[i][C1] = ans;
            }
        }
    }
    for (auto i : keys3) {
        for (auto j : keys23[i]) {
            if (mp3[i][j] != 0) {
                std::cout << i << ' ' << j << ' ' << mp3[i][j] << std::endl;
            }
        }
    }
    return 0;
}
