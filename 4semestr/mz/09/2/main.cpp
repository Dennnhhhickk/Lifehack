#include <iostream>
#include <string>

class Result
{
    int64_t _value;
public:
    Result()
    {
        _value = 0;
    }
    Result(int64_t a)
    {
        _value = a;
    }
    int64_t value()
    {
        return _value;
    }
    void getValue(int64_t a)
    {
        _value = a;
    }
    ~Result(){};
};

void func(int64_t a, int64_t b, uint32_t k)
{
    // This function calculates the value of the function given in the condition using try-catch blocks
    if (k == 0) {
        Result r{a + b};
        throw r;
    }
    if (k > 0 && b == 1) {
        Result r{a};
        throw r;
    }
    if (k > 0 && b > 1) {
        int64_t tmp{0};
        try {
            func(a, b - 1, k);
        } catch (Result r) {
            tmp = r.value();
        }
        func(a, tmp, k - 1);
    }
}

int main()
{
    int64_t a, b;
    uint32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result r) {
            std::cout << r.value() << std::endl;
        }
    }
    return 0;
}
