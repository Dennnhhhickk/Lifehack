#include <iostream>
#include <ctime>
#include <boost/date_time/gregorian/gregorian_types.hpp>

int main()
{
    using namespace boost::gregorian;
    uint32_t y, m, d, y1, m1, d1;
    char ch;
    // date date1(2012, Apr, 2);
    // date date2(2003, Feb, 2);
    std:: cin >> y >> ch >> m >> ch >> d;
    uint64_t ans = 0;
    while (std:: cin >> y1 >> ch >> m1 >> ch >> d1) {
        // std::cout << m << ' ' << m1 << std::endl;
        date date1(y, m, d);
        date date2(y1, m1, d1);
        long difference = (date1 - date2).days();
        ans += std::abs(difference);
        // std::cout << difference << std::endl;
        y = y1;
        m = m1;
        d = d1;
    }
    std::cout << ans << std::endl;
    return 0;
}
