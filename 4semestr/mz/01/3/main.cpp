#include <iostream>
#include <iomanip>   
#include <cmath>
#include <ios>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int k = 0;
    char lst = 'a';
    char ch;
    while (std::cin.get(ch)) {
        if (isdigit(lst) && lst != '0') {
            k = 1;
        }
        if (!isdigit(ch) && lst == '0' && k == 0) {
            std::cout << lst;
        }
        if (!(ch == '0' && k == 0)) {
            std::cout << ch;
        }
        if (!isdigit(ch)) {
            k = 0;
        }
        lst = ch;
    }
    if (k == 0 && lst == '0') {
        std::cout << lst;
    }
    return 0;
}
