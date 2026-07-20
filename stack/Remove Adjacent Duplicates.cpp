#include <bits/stdc++.h>
using namespace std;
auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();

signed main() {
    auto Problem = [](const string &str) {
        stack<char> s;
        for (char x : str) {
            if (!s.empty() && s.top() == x) {
                s.pop();
            } else {
                s.push(x);
            }
        }
        string r;
        while (!s.empty()) {
            r.push_back(s.top());
            s.pop();
        }
        return string(r.rbegin(), r.rend());
    };
}

