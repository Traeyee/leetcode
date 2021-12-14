/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-04 17:30
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
    int longestSubstring(string s, int k) {
        int n = s.size();

        unordered_map<char, int> counter;
        for (const auto& c : s) {
            counter[c]++;
        }
        int max_len = 0;

        int i = 0, j = 0;
        unordered_map<char, int> tmp_counter;
        int invalid_cnt = 0;
        while (j < n) {
            if (counter[s[j]] < k) {
                while (i < j) {
                    tmp_counter[s[i]]--;
                    if (k - 1 == tmp_counter[s[i]]) {
                        invalid_cnt++;
                    }
                    if (0 == tmp_counter[s[i]]) {
                        invalid_cnt--;
                    }
                    i++;
                    cout << "# " << i << ", " << j << ": " << invalid_cnt
                         << '\n';
                    if (0 == invalid_cnt) {
                        max_len = j - i > max_len ? j - i : max_len;
                    }
                }
                // 中断，然后重新开始
                tmp_counter.clear();
                invalid_cnt = 0;
                i = j + 1;
                j = i;
            } else {
                tmp_counter[s[j]]++;
                if (1 == tmp_counter[s[j]]) {
                    invalid_cnt++;
                }
                if (k == tmp_counter[s[j]]) {
                    invalid_cnt--;
                }
                j++;
                if (0 == invalid_cnt) {
                    max_len = j - i > max_len ? j - i : max_len;
                }
            }
            // i...j-1
            // cout << "# " << i << ", " << j << ": " << invalid_cnt << '\n';
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    s = "aaabb", k = 3;
    cout << sol.longestSubstring(s, k) << '\n';

    s = "ababbc", k = 2;
    cout << sol.longestSubstring(s, k) << '\n';

    s = "bbaaacbd", k = 3;
    cout << sol.longestSubstring(s, k) << '\n';

    s = "baaabcb", k = 3;
    cout << sol.longestSubstring(s, k) << '\n';

    return 0;
}