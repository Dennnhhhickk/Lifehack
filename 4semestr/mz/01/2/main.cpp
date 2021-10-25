#include <iostream>
#include <vector>

class A
{
public:
    int get() const
    {
        return a_;
    }

    A()
    {
        std::cin >> a_;
        log_ = 0;
    }

    A(A &a)
    {
        log_ = 1;
        std::cin >> a_;
        a_ += a.get();
    }

    ~A()
    {
        if (log_ == 1) {
            std::cout << a_ << std::endl;
        }
    }

private:
    int a_{};
    int log_{};
};
