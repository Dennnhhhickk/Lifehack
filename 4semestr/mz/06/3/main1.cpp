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
    uint32_t R, C, V;
    while (std::cin >> R >> C >> V) {
        if (R == 0 && C == 0 && V == 4294967161) {
            break;
        }
        mp[(uint64_t)R][(uint64_t)C] = (uint64_t)V;
    }
    while (std::cin >> R >> C >> V) {
        mp1[(uint64_t)R][(uint64_t)C] = (uint64_t)V;
    }
    uint64_t ans = 0;
    for (auto i : mp1) {
        for (auto j : i.second) {
            for (auto i1 : mp) {
                ans = 0;
                for (auto j1 : i1.second) {
                    ans = (ans + ((mp[i1.first][j1.first] % 4294967161) * (mp1[j1.first][j.first] % 4294967161))% 4294967161) % 4294967161;
                }
                mp3[i1.first][j.first] = ans;
            }
        }
    }
    for (auto i : mp3) {
        for (auto j : i.second) {
            if (j.second != 0) {
                std::cout << i.first << ' ' << j.first << ' ' << j.second << std::endl;
            }
        }
    }
    return 0;
}
