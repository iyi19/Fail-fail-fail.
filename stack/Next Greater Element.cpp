#include <bits/stdc++.h>
using namespace std;
auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();

signed main() {
    auto Problem = [&](vector<int>& x) {
        int n = x.size();
        stack<int> s;
        vector<int> r(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= x[i])
                s.pop();
            if (s.empty())
                r[i] = -1;
            else
                r[i] = s.top();
            s.push(x[i]);
        }
        return r;
    };
    return 0;
}
/*
Traverse from right to left.
Remove all elements that are smaller than or equal to the current element.
The first element remaining in the stack is the answer.
Push the current element onto the stack.
*/

