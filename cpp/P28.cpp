/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 07:57
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
    int strStr(string haystack, string needle) {
        int s_len = haystack.size(), p_len = needle.size();
        // 使得不用担心j越界
        if (s_len < p_len) {
            return -1;
        }

        vector<unordered_map<char, int>> dp(p_len, unordered_map<char, int>());
        // 构造dp数组
        // dp[i]定义：当c != needle[i]时，可通过dp[i][c]返回到某个状态s[k]：s[k - 1] --c--> s[k]
        // 最坏的情况是所有匹配失败都回到0
        // 定义状态x: 和当前状态具有相同的前缀，且最长（因为短的那些你至少可在后面处理）
        int x;
        for (int i1 = 0; i1 < p_len; i1++) {
            char c = needle[i1];
            dp[i1][c] = i1 + 1;
            x = dp[x][c];
        }

        int j = 0;  // pattern当前要check的位置，同时也是状态机里的状态代号
        for (int i = 0; i < s_len; i++) {
            if (haystack[i] == needle[j]) {
                j++;
            } else {
                j = dp[j][haystack[i]];
            }
        }

        // TODO: 返回索引

    }






















    // 思考过程，太快地自然到了next的思路了，但不容易想清楚，得backoff一下
    int strStr1_0(string haystack, string needle) {
        // fail指针：
        // 对于c_i = needle[i]失败了, 如果有needle[p...i-1] == needle[0...q]
        // 则可以试从q+1再试，即fail[i] = q + 1
        // 怎么求fail[i]？令ptr = fail[i]，若needle[ptr] == needle[i]，则
        int fail[needle.size()];
        fail[0] = -1;
        int pos;

        fail[pos];

        int j = 0;  // 现在要看的needle的位置
        int i = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = fail[j];
                if (-1 == j) {
                    i++;
                    j = 0;
                }
            }
        }
        if (needle.size() == j) {
            // TODO: 匹配成功
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

    return 0;
}