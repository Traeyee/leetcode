/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 08:44
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
    void generateParenthesis(int n4left, int n4right, string& cur_string,
                             vector<string>& res) {
        if (0 == n4left && 0 == n4right) {
            res.push_back(cur_string);
            return;
        }

        if (n4left > 0) {
            cur_string.push_back('(');
            generateParenthesis(n4left - 1, n4right + 1, cur_string, res);
            cur_string.pop_back();
        }

        if (n4right > 0) {
            cur_string.push_back(')');
            generateParenthesis(n4left, n4right - 1, cur_string, res);
            cur_string.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        generateParenthesis(n, 0, s, res);
        return res;
    }
};

int main() {
    Solution sol;
    int n;

    n = 3;
    for (auto ele : sol.generateParenthesis(n)) {
        cout << ele << ", ";
    }
    cout << "\n";

    n = 1;
    for (auto ele : sol.generateParenthesis(n)) {
        cout << ele << ", ";
    }
    cout << "\n";
    
    return 0;
}