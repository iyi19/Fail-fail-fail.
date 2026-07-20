#include <bits/stdc++.h>
using namespace std;
auto _ = []()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();

signed main() {
    auto Problem = [&](const string &str) {
        stack<char> s;
        for (char c : str) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else {
                if (s.empty())
                    return false;

                if (c == ')' && s.top() != '(')
                    return false;
                if (c == ']' && s.top() != '[')
                    return false;
                if (c == '}' && s.top() != '{')
                    return false;

                s.pop();
            }
        }
        return s.empty();
    };
    return 0;
}

