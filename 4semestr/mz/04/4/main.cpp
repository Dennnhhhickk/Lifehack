#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Sum
{
public:
    void operator()(double n)
    {
        sum = (sum * count + n) / (count + 1);
        ++count;
    };
    double sum{0};
    double count{0};
};

int main()
{
    std::vector<double> a;
    double f;
    while (std::cin >> f) {
        a.push_back(f);
    }
    int size = a.size();
    a.erase(a.begin(), a.begin() + size / 10);
    a.erase(a.end() - size / 10, a.end());
    std::sort(a.begin(), a.end());
    size = a.size();
    a.erase(a.begin(), a.begin() + size / 10);
    a.erase(a.end() - size / 10, a.end());
    Sum res = std::for_each(a.begin(), a.end(), Sum());
    std::cout << std::setprecision(10) << std::fixed << res.sum << std::endl;
    return 0;
}
