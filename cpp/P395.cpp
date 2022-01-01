/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-04 17:30
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    int _longestSubstring(string s, int l, int r, int k) {
        int n = s.size();
        if (!(0 <= l && l <= r && r < n)) {
            return 0;
        }
        cout << "# " << l << ", " << r << '\n';
        map<int, int> counter;
        for (int i = l; i <= r; i++) {
            counter[s[i]]++;
        }
        
        int max_len = 0;
        int start = -1;
        bool all_no_less_than_k = true;
        for (int i = l; i <= r; i++) {
            if (counter[s[i]] < k) {
                int sub_len = _longestSubstring(s, start, i - 1, k);
                max_len = sub_len > max_len ? sub_len : max_len;
                start = -1;
                all_no_less_than_k = false;
            } else {
                if (-1 == start) {
                    start = i;
                }
            }
        }
        if (all_no_less_than_k) {
            return r - l + 1;
        }
        if (counter[s[r]] >= k) {
            int sub_len = _longestSubstring(s, start, n - 1, k);
            max_len = sub_len > max_len ? sub_len : max_len;
        }

        return max_len;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        return _longestSubstring(s, 0, n - 1, k);
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // s = "aaabb", k = 3;
    // cout << sol.longestSubstring(s, k) << '\n';

    // s = "ababbc", k = 2;
    // cout << sol.longestSubstring(s, k) << '\n';

    s = "bbaaacbd", k = 3;
    cout << sol.longestSubstring(s, k) << '\n';

    // s = "baaabcb", k = 3;
    // cout << sol.longestSubstring(s, k) << '\n';

    return 0;
}