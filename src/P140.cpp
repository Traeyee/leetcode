/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 19:29
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>());

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                string subw = s.substr(i, j - i + 1);
                if (word_set.end() != word_set.find(subw)) {
                    if (j + 1 < n) {
                        for (const auto& subw2 : dp[j + 1]) {
                            string s2 = subw + " " + subw2;
                            dp[i].emplace_back(s2);
                        }
                    } else {
                        dp[i].emplace_back(subw);
                    }
                }
            }
        }

        return dp[0];
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    string s;
    vector<string> wordDict;
    vector<string> res;

    s = "catsanddog", wordDict = {"cat", "cats", "and", "sand", "dog"};
    res = sol.wordBreak(s, wordDict);
    print_vector(res);

    s = "pineapplepenapple",
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    res = sol.wordBreak(s, wordDict);
    print_vector(res);

    s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"};
    res = sol.wordBreak(s, wordDict);
    print_vector(res);

    return 0;
}