#include <vector>
#include <functional>

template <typename T, typename F>
void myapply(T st, T fn, F f)
{
    for (auto it = st; it != fn; ++it) {
        f(*it);
    }
}

template <class T, typename F>
std::vector<std::reference_wrapper <typename T::value_type > > myfilter2(T st, T fn, F f)
{
    std::vector<std::reference_wrapper <typename std::iterator_traits<T>::value_type > > ans;
    for (auto it = st; it != fn; ++it) {
        if (f(*it)) {
            ans.push_back(*it);
        }
    }
    return ans;
}
