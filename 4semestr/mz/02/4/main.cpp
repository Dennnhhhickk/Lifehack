#include <iostream>
#include <ios>
#include <string>
#include <iomanip>

enum { N = 4096 };

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    char ch;
    std::cin.get(ch);
    if (ch == '\0' || std::cin.eof()) {
        return 0;
    }
    char lst = ch;
    int k = 1;
    while (std::cin.get(ch)) {
        if (ch == '\0') {
            break;
        }
        if (ch == lst) {
            k++;
        } else {
            if (k <= 4 && lst != '#') {
                for (int i = 0; i < k; i++) {
                    std::cout << lst;
                }
            } else {
                std::stringstream ss;
                ss << std::hex << k;
                std::string res (ss.str());
                std::cout << '#' << lst << res << '#';
            }
            k = 1;
            lst = ch;
        }
    }
    if (k <= 4 && lst != '#') {
        for (int i = 0; i < k; i++) {
            std::cout << lst;
        }
    } else {
        std::stringstream ss;
        ss << std::hex << k;
        std::string res (ss.str());
        std::cout << '#' << lst << res << '#';
    }
    return 0;
}
