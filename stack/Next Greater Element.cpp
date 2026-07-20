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
    auto NextGreaterElement = [&]() {
        stack<int> s;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= x[i])
                s.pop();
            if (s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();
            s.push(x[i]);
        }
        return ans;
    };
    return 0;
}
