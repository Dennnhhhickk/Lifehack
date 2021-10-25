#include <vector>

void process(std::vector<long long> &a, long long z)
{
    int size = a.size();
    int add = 0, p = 0;
    for (int i = 0; i < size; ++i) {
        auto it = a.rbegin();
        it += 2 * add + p;
        if (*it >= z) {
            a.push_back(*it);
            ++add;
        } else {
            ++p;
        }
    }
}
