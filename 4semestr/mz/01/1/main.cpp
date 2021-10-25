#include <iostream>
#include <vector>

class Sum
{
public:
    int get() const
    {
        return a_ + b_;
    }

    Sum(int a, int b)
    {
        a_ = a;
        b_ = b;
    }

    Sum(Sum a, int b)
    {
        a_ = a.get();
        b_ = b;
    }

private:
    int a_{}, b_{};
};
