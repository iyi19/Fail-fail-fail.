#include <bits/stdc++.h>
using namespace std;
auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();

signed main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &&i : x)
        cin >> i;
    stack<int> s;
    vector<int> ans(n, -1);
    for (int i = 0; i < 2 * n; ++i) {
        while (!s.empty() && s.top() <= x[i % n])
            s.pop();
        if (i >= n && !s.empty())
            ans[i % n] = s.top();
        s.push(x[i % n]);
    }
    return 0;
}
