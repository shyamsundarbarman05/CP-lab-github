#include <bits/stdc++.h>
using namespace std;

int start = 0, maxLen = 1;  // make them global or pass by reference

void expand(string &s, int l, int r) {
    int n = s.size();
    while (l >= 0 && r < n && s[l] == s[r]) {
        if (r - l + 1 > maxLen) {
            start = l;
            maxLen = r - l + 1;
        }
        l--; r++;
    }
}

string longestPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        expand(s, i, i);     // odd length palindrome
        expand(s, i, i + 1); // even length palindrome
    }
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}


// 1. Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"

// Output: "bab"

// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"

// Output: "bb"

// Constraints:

// 1 <= s.length <= 1000

// s consist of only digits and English letters.