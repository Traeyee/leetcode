/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-08 11:47
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
    // 这个写法可能有错
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int l = 0, r = 0, max_len = 0;

        unordered_map<char, int> counter;

        while (r < n) {
            char c = s[r];
            // 切记unordered_map::count是key的数目，不是key的value，所以永远是1！
            while (l < r && counter[c]) {
                counter[s[l]]--;
                l++;
            }

            // cout << "# " << s.substr(l, r - l + 1) << "\n";
            max_len = max({r - l + 1, max_len});
            counter[c]++;
            r++;
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    string s;

    s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << "\n";

    s = "bbbbb";
    cout << sol.lengthOfLongestSubstring(s) << "\n";

    s = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s) << "\n";

    s = "dvdf";
    cout << sol.lengthOfLongestSubstring(s) << "\n";

    return 0;
}