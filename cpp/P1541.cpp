/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-08 17:30
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
    int minInsertions(string s) {
        int left_prths = 0, moves = 0;
        bool wait_for_right = false;
        for (char c : s) {
            if ('(' == c) {
                if (wait_for_right) {
                    moves++;
                    wait_for_right = false;
                }
                left_prths++;
            } else {
                if (wait_for_right) {
                    wait_for_right = false;
                } else {
                    if (left_prths > 0) {
                        left_prths--;
                    } else {
                        moves++;
                    }
                    wait_for_right = true;
                }
            }
            // cout << left_prths << ", " << moves << ", " << wait_for_right << '\n';
        }

        int res = left_prths * 2 + moves;
        if (wait_for_right) {
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "(()))";
    cout << sol.minInsertions(s) << '\n';

    s = "())";
    cout << sol.minInsertions(s) << '\n';

    s = "))())(";
    cout << sol.minInsertions(s) << '\n';

    return 0;
}