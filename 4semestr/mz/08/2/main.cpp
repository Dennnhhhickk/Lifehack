#include <cmath>
#include <algorithm>

template<class T>
typename T::value_type dist(T field, T a, T b)
{
    // return a.row + b.row;
    return std::max(std::min(std::abs(a.row - b.row), (field.row - std::max(a.row, b.row)) +
                std::min(a.row, b.row)), std::min(std::abs(a.col - b.col),
                (field.col - std::max(a.col, b.col)) + std::min(a.col, b.col)));
}

template<typename T>
class Coord {
public:
    typedef T value_type;
    T row, col;
    Coord()
    {
        row = 0;
        col = 0;
    }

    Coord(T a)
    {
        row = a;
        col = a;
    }

    Coord(T x, T y)
    {
        row = x;
        col = y;
    }
};
