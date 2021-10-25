#include <vector>

void process(
        const std::vector<unsigned long long> &a,
        std::vector<unsigned long long> &b,
        unsigned int step)
{
    auto it = b.rbegin();
    for (auto i = a.begin(); i < a.end(); i += step) {
        if (it != b.rend()) {
            *it += *i;
            ++it;
        } else {
            break;
        }
    }
}
