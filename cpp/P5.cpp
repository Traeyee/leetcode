/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 09:59
 * @brief  DP思路不适合回文串的结构，这个解法TL
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<string>> memo(n, vector<string>());
        string longest = s.substr(0, 1);

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                for (const auto& palindrome : memo[i - 1]) {
                    int i1 = i - 1 - palindrome.size();
                    if (i1 >= 0 && s[i] == s[i1]) {
                        auto new_palindrome =
                            s.substr(i1, palindrome.size() + 2);
                        memo[i].push_back(new_palindrome);
                        longest = new_palindrome.size() > longest.size()
                                      ? new_palindrome
                                      : longest;
                        break;
                    }
                }
            }
            if (i - 1 >= 0 && s[i] == s[i - 1]) {
                auto new_palindrome = s.substr(i - 1, 2);
                longest = new_palindrome.size() > longest.size()
                              ? new_palindrome
                              : longest;
                memo[i].push_back(new_palindrome);
            }
            memo[i].push_back(s.substr(i, 1));
        }

        return longest;
    }
};

int main() {
    Solution sol;
    string s;

    s = "babad";
    cout << sol.longestPalindrome(s) << "\n";

    s = "cbbd";
    cout << sol.longestPalindrome(s) << "\n";

    s = "a";
    cout << sol.longestPalindrome(s) << "\n";

    s = "ac";
    cout << sol.longestPalindrome(s) << "\n";

    s = "ccc";
    cout << sol.longestPalindrome(s) << "\n";

    s = "aaaaa";
    cout << sol.longestPalindrome(s) << "\n";

    return 0;
}