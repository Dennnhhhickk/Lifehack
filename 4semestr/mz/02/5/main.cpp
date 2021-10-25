#include <string>
#include <iostream>
#include <algorithm>

class BinaryNumber
{
public:
    BinaryNumber(const std::string &s)
    {
        s_.resize(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            s_[i] = s[i];
        }
    };

    operator std::string() const
    {
        return s_;
    };

    const BinaryNumber &operator++()
    {
        size_t k = 0;
        std::reverse(s_.begin(), s_.end());
        while (s_[k] == '1' && k < s_.size()) {
            k++;
        }
        if (s_.size() == k) {
            s_.resize(k + 1);
            s_[k] = '0';
        }
        size_t l = 0;
        while (s_[l] == '1' && l < s_.size()) {
            s_[l] = '0';
            l++;
        }
        s_[l] = '1';
        std::reverse(s_.begin(), s_.end());
        return *this;
    };
private:
    std::string s_;
};
