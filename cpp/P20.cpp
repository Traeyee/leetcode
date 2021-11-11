/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-10 11:03
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
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> paranthesis_map = {
            {')', '('}, {']', '['}, {'}', '{'}};
        for (const auto& c : s) {
            if ('(' == c || '{' == c || '[' == c) {
                stk.push(c);
            } else {
                // 教训：使用stack.top()一定要先判断是否非空
                if (!stk.empty() && stk.top() == paranthesis_map[c]) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution sol;
    string s;

    s = "()";
    cout << sol.isValid(s) << "\n";

    s = "()[]{}";
    cout << sol.isValid(s) << "\n";

    s = "(]";
    cout << sol.isValid(s) << "\n";

    s = "([)]";
    cout << sol.isValid(s) << "\n";

    s = "{[]}";
    cout << sol.isValid(s) << "\n";

    return 0;
}