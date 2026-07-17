#include <bits/stdc++.h>
auto _ = []() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();
signed main() {
    auto bad = [&](const std::vector<int> &x, int k) {
        std::unordered_map<int, int> mp;
        mp[0] = 1;
        int64_t t = {};
        int r = {};
        for (auto i : x) {
            t += i;
            r += mp[t - k];
            ++mp[t];
        }
        return r;
    };
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> x(n);
    for (auto &&i : x) {
        std::cin >> i;
    }
    int r = bad(x, k);
    std::cerr << r << std::endl;
    return 0;
}
