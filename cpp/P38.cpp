/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-18 11:04
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
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
    string countAndSay(int n) {
        string res("1"), tmp_res;
        int cnt;
        char c;
        for (int i = 1; i < n; i++) {
            int j = 0;
            tmp_res.clear();
            while (j < res.size()) {
                c = res[j];
                cnt = 0;
                while (j < res.size() && res[j] == c) {
                    cnt++;
                    j++;
                }
                tmp_res.push_back(cnt + '0');
                tmp_res.push_back(c);
            }
            res = tmp_res;
        }

        return res;
    }
};

int main() {
    Solution sol;
    int n;

    n = 1;
    cout << sol.countAndSay(n) << '\n';

    n = 4;
    cout << sol.countAndSay(n) << '\n';

    return 0;
}