/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 19:08
 * @brief
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());

        for (int i = 0; i < n; i++) {
            if (0 <= i - 1 && !dp[i - 1]) {
                continue;
            }
            for (int j = i; j < n; j++) {
                string subs1 = s.substr(i, j - i + 1);
                // cout << subs1 << "\n";
                if (word_set.end() != word_set.find(subs1)) {
                    if (n - 1 == j) {
                        return true;
                    }
                    dp[j] = true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string> wordDict;

    s = "leetcode", wordDict = {"leet", "code"};
    cout << sol.wordBreak(s, wordDict) << "\n";

    s = "applepenapple", wordDict = {"apple", "pen"};
    cout << sol.wordBreak(s, wordDict) << "\n";

    s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak(s, wordDict) << "\n";

    return 0;
}