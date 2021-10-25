template <typename T, typename F>
T myfilter(const T &a, F f)
{
    T ans = {};
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (f(*it)) {
            ans.insert(ans.end(), *it);
        }
    }
    return ans;
}
