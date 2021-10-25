#include <iostream>
#include <vector>
#include <algorithm>
// #include "1.h"
// #include "2.h"

int main()
{
    Circle *c;
    Square *sq;
    Rectangle *r;
    std::vector < std::pair<double, std::string> > a;
    std::string s;
    char ch = '0';
    while (getline(std::cin, s)) {
        auto i = s.begin();
        while (i != s.end()) {
            if (isalpha(*i)) {
                ch = *i;
                s.erase(s.begin(), i + 1);
            }
            ++i;
        }
        if (ch == 'R') {
            r = Rectangle::make(s);
            a.push_back(make_pair(r->get_square(), r->to_string()));
            delete r;
        }
        if (ch == 'C') {
            c = Circle::make(s);
            a.push_back(make_pair(c->get_square(), c->to_string()));
            delete c;
        }
        if (ch == 'S') {
            sq = Square::make(s);
            a.push_back(make_pair(sq->get_square(), sq->to_string()));
            delete sq;
        }
    }
    std::stable_sort(a.begin(), a.end(), [](const std::pair<double, std::string> &a,
            const std::pair<double, std::string> &b) { return (a.first < b.first); });
    for (auto i : a) {
        std::cout << i.second << std::endl;
    }
    return 0;
}
