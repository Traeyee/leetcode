/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 19:36
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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            auto& itvl1 = firstList[i];
            auto& itvl2 = secondList[j];

            if (itvl1[1] < itvl2[1]) {
                if (itvl2[0] <= itvl1[1]) {
                    // 1) 相交
                    int left_end = itvl1[0] <= itvl2[0] ? itvl2[0] : itvl1[0];
                    vector<int> tmp = {left_end, itvl1[1]};
                    ret.emplace_back(tmp);
                } else {
                    // 2) 错过
                }
                i++;
            } else if (itvl2[1] < itvl1[1]) {
                if (itvl1[0] <= itvl2[1]) {
                    // 1) 相交
                    int left_end = itvl1[0] <= itvl2[0] ? itvl2[0] : itvl1[0];
                    vector<int> tmp = {left_end, itvl2[1]};
                    ret.emplace_back(tmp);
                } else {
                    // 2) 错过
                }
                j++;
            } else {
                int left_end = itvl1[0] <= itvl2[0] ? itvl2[0] : itvl1[0];
                vector<int> tmp = {left_end, itvl1[1]};
                ret.emplace_back(tmp);
                i++;
                j++;
            }
        }

        // itvl1的end一直比较小，最后一个还是比较小，不用再找
        // 其它情况想想就明白

        return ret;
    }
};

void print_intervals(vector<vector<int>>& intervals) {
    for (const auto& itvl : intervals) {
        cout << "[" << itvl[0] << ", " << itvl[1] << "], ";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    vector<vector<int>> firstList, secondList;
    vector<vector<int>> res;

    firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
    secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    res = sol.intervalIntersection(firstList, secondList);
    print_intervals(res);

    firstList = {{1, 3}, {5, 9}}, secondList = {};
    res = sol.intervalIntersection(firstList, secondList);
    print_intervals(res);
    
    firstList = {}, secondList = {{4, 8}, {10, 12}};
    res = sol.intervalIntersection(firstList, secondList);
    print_intervals(res);
    
    firstList = {{1, 7}}, secondList = {{3, 10}};
    res = sol.intervalIntersection(firstList, secondList);
    print_intervals(res);

    return 0;
}