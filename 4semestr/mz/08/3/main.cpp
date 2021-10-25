#include <cmath>
#include <algorithm>

namespace Game
{
    template<class T>
    typename T::value_type dist(T field, T a, T b)
    {
        // return a.row + b.row;
        // return std::max(std::min(std::abs(a.row - b.row), (field.row - std::max(a.row, b.row)) +
        //             std::min(a.row, b.row)), std::min(std::abs(a.col - b.col),
        //             (field.col - std::max(a.col, b.col)) + std::min(a.col, b.col)));
        typename T::value_type ans = std::abs(a.col - b.col);
        ans += std::abs((a.row - (a.col + a.col % 2) / 2) - (b.row - (b.col + b.col % 2) / 2));
        ans += std::abs(b.col + (b.row - (b.col + b.col % 2) / 2) - a.col - (a.row - (a.col + a.col % 2) / 2));
        return ans / 2;
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
} // namespace Game
