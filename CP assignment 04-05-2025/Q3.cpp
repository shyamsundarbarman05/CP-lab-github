#include <bits/stdc++.h>
using namespace std;

void solve(int n, int open, int close, string cur, vector<string> &ans) {
    if (cur.size() == 2*n) {
        ans.push_back(cur);
        return;
    }
    if (open < n) solve(n, open+1, close, cur+"(", ans);
    if (close < open) solve(n, open, close+1, cur+")", ans);
}

int main() {
    int n;
    cin >> n;
    vector<string> ans;
    solve(n, 0, 0, "", ans);
    for (auto &s : ans) cout << s << "\n";
}
// 3. Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


// Example 1:

// Input: n = 3

// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1

// Output: ["()"]


// Constraints:

// 1 <= n <= 8