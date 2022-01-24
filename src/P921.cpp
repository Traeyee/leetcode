/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-08 17:22
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
    int minAddToMakeValid(string s) {
        int left_para_cnt = 0;
        int moves = 0;
        for (char c : s) {
            if ('(' == c) {
                left_para_cnt++;
            } else {
                if (left_para_cnt > 0) {
                    left_para_cnt--;
                } else {
                    moves++;
                }
            }
        }

        return moves + left_para_cnt;
    }
};

int main() {
    Solution sol;
    string s;

    s = "())";
    cout << sol.minAddToMakeValid(s) << '\n';

    s = "(((";
    cout << sol.minAddToMakeValid(s) << '\n';

    s = "()";
    cout << sol.minAddToMakeValid(s) << '\n';

    s = "()))((";
    cout << sol.minAddToMakeValid(s) << '\n';

    return 0;
}