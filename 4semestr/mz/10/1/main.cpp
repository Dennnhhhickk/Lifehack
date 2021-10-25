#include <iostream>
#include <string>

int check(std::string s)
{
    bool bol = true;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '3' || s[i] == '4') {
            if (!bol) {
                return 0;
            }
        } else if (s[i] == '1' || s[i] == '2') {
            bol = false;
        } else {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::string s;
    while (std::cin >> s) {
        std::cout << check(s) << std::endl;
    }
}
