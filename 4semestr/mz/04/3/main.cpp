#include <vector>
#include <algorithm>

void process(const std::vector<int> &a, std::vector<int> &b)
{
    std::vector<int> c = a;
    std::sort(c.begin(), c.end());
    c.erase(std::unique(begin(c), end(c)), end(c));
    auto st = b.begin();
    auto sn = c.begin();
    while (sn != c.end() && *sn < 0) {
        ++sn;
    }
    for (auto it = b.begin(); it != b.end(); ++it) {
        if (sn != c.end() && *sn == it - b.begin()) {
            ++sn;
        } else {
            std::swap(*st, *it);
            ++st;
        }
    }
    b.erase(st, b.end());
}
