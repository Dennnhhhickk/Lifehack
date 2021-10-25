template <typename T>
typename T::value_type process(const T &a)
{
    typename T::value_type ans = {};
    if (a.end() == a.begin()) {
        return ans;
    }
    auto it = a.end();
    --it;
    ans += *(it);
    --it;
    if (it == a.begin()) {
        return ans;
    }
    --it;
    ans += *(it);
    if (it == a.begin()) {
        return ans;
    }
    --it;
    if (it == a.begin()) {
        return ans;
    }
    --it;
    ans += *(it);
    return ans;
}
