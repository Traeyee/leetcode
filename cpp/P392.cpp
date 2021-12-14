/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-13 22:50
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
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;
        while (p1 < s.size() && p2 < t.size()) {
            if (s[p1] == t[p2]) {
                p1++;
            }
            p2++;
        }
        return p1 == s.size();
    }
};

int main() {
    Solution sol;
    string s, t;

    s = "abc", t = "ahbgdc";
    cout << sol.isSubsequence(s, t) << '\n';

    s = "axc", t = "ahbgdc";
    cout << sol.isSubsequence(s, t) << '\n';

    return 0;
}