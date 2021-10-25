#include <iostream>
#include <string>

class stack
{
    std::string s;
public:
    stack()
    {
        s = "";
    }   
    int in()
    {
        if (std::cin >> s) {
            return 1;
        }
        return 0;
    }
    ~stack()
    {
        if (s.size() > 0) {
            std::cout << s << std::endl;
        }
    }
};

void func()
{
    stack st{};
    if (st.in()) {
        func();
    }
    throw 1;
}

int main()
{
    try {
        func();
    } catch (int a) {

    }
    return 0;
}
