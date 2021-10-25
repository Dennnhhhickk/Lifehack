#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return 0;
    }

    std::vector<std::string> a;
    for (int i = 4; i < argc; ++i) {
        a.push_back((std::string(argv[i])));
    }
    numbers::complex C((std::string(argv[1])));
    double R = std::stod((std::string(argv[2])));
    int N = std::stoi((std::string(argv[3])));
    double step = M_PI * (double)2.0 / N;
    numbers::complex curr, prev(R + C.re(), C.im()), z;
    numbers::complex ans(0, 0);
    for (int i = 1; i <= N; ++i) {
        curr = numbers::complex(cos((i - 0.5) * step) * R + C.re(), sin((i - 0.5) * step) * R + C.im());
        ans += numbers::eval(a, curr) * step * numbers::complex(-R * sin((i - 0.5) * step), R * cos((i - 0.5) * step));
        prev = curr;
    }
    std::cout << ans.to_string() << std::endl;
    return 0;
}
