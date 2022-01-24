/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 07:57
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
    int strStr(string haystack, string needle) {
        int s_len = haystack.size(), p_len = needle.size();
        // 使得不用担心j越界
        if (0 == p_len) {
            return 0;
        }
        if (s_len < p_len) {
            return -1;
        }

        // 计算next
        vector<int> next(p_len, 0);
        next[0] = -1;
        // next[j] = i 意味着 p[0...i-1]匹配上了p[j-i...j-1]
        // 对于j，若p[j] == p[i]，则next[j + 1] = i + 1;
        // 否则，i = next[i];
        int i = next[0], j = 0;
        while (j < p_len - 1) {
            if (-1 == i || needle[j] == needle[i]) {
                i++;
                j++;
                next[j] = i;
            } else {
                i = next[i];
            }
        }

        i = 0, j = 0;
        while (i < s_len && j < p_len) {
            if (-1 == j || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == p_len) {
            // 5, 2, i = 5, j = 2
            return i - j;
        }
        return -1;
    }

    // base: O(mn)
    int strStr0(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        // 教训：不要轻易让size_t相减，因为负数会溢出
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            // cout << "# here: " << haystack.size() << ", " << needle.size() <<
            // "\n"; cout << "# here2: " << i << "--" << haystack.size() -
            // needle.size() << "\n";
            bool failed = false;
            for (int j = 0, i1 = i; j < needle.size(); j++, i1++) {
                if (haystack[i1] != needle[j]) {
                    failed = true;
                    break;
                }
            }
            if (!failed) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack, needle;

    haystack = "hello", needle = "ll";
    cout << sol.strStr(haystack, needle) << "\n";

    haystack = "aaaaa", needle = "bba";
    cout << sol.strStr(haystack, needle) << "\n";

    haystack = "", needle = "";
    cout << sol.strStr(haystack, needle) << "\n";

    haystack = "", needle = "a";
    cout << sol.strStr(haystack, needle) << "\n";

    haystack = "mississippi", needle = "issip";
    cout << sol.strStr(haystack, needle) << "\n";

    haystack = "aabaaabaaac", needle = "aabaaac";
    cout << sol.strStr(haystack, needle) << "\n";

    return 0;
}