#include <iostream>
#include <iomanip>   
#include <cmath>

int main()
{
    double a = 0, b = 0, q = 0, lst;
    int k = 0;
    std::cout << std::setprecision(10) << std::fixed;
    while (std::cin >> b) {
        k++;
        lst = a;
        a += (b - a) / (1.0 * k);
        // std::cout << a << std::endl;
        q += (b - a) * (b - lst);
        // std::cout << sqrt(q / k) << std::endl;
    }
    std::cout << a << std::endl;
    std::cout << sqrt(q / k) << std::endl;
}
