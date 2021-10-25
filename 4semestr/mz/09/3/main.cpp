#include <iostream>

class S
{
    int value;
    bool readed;
public:
    S()
    {
        readed = (bool)(std::cin >> value);
    }
    ~S()
    {
        if (readed) {
            std::cout << value << std::endl;
        }
    }
    S(S &&a)
    {
        readed = (bool)(std::cin >> value);
        if (readed && a.readed) {
            a.readed = false;
            value += a.value;
        }
    }
    operator bool()
    {
        return readed;
    }
};
