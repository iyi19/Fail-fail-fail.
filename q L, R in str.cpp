/**
 *    created:  17.07.2026 20:59:19
**/

#include <bits/stdc++.h>
auto _ = []() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();
signed main() {
    auto bad = [&](const std::string& str) {
        int n = (int)str.length();
        std::vector<std::vector<int>> pre(26, std::vector<int>(n + 1));
        for(int i = {}; i < n; ++i) {
            for(int j = {}; j < 26; ++j) {
                pre[j][i + 1] = pre[j][i];
            }
            ++pre[str[i] - 'a'][i + 1];
        }
        int t;
        std::cin >> t;
        while(t--) {
            int i, j;
            char x;
            // --i, --j;
            std::cin >> i >> j >> x;
            int r = pre[x - 'a'][j + 1] - pre[x - 'a'][i];
            std::cerr << r << '\n';
        }
    };
    std::string str;
    std::cin >> str;
    bad(str);
    return 0;
}

/*
time -> O(26n + t)
q    -> O(1)
*/
