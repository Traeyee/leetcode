/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 12:14
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
    // 瞎jb先排序版
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& x1, vector<int>& x2) {
            return x1[0] < x2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ret;

        int this_start = intervals[0][0], rightmost_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            auto& itvl = intervals[i];
            if (itvl[0] <= rightmost_end) {
                // 继续合
                rightmost_end =
                    itvl[1] >= rightmost_end ? itvl[1] : rightmost_end;
            } else {
                // 分离
                vector<int> tmp = {this_start, rightmost_end};
                ret.emplace_back(tmp);
                this_start = itvl[0];
                rightmost_end = itvl[1];
            }
        }
        vector<int> last_interval = {this_start, rightmost_end};
        ret.emplace_back(last_interval);

        return ret;
    }
    
    // 逻辑没错，可惜题目意思是这样的
    // Input
    // [[1,4],[0,0]]
    // Output
    // [[1,4]]
    // Expected
    // [[0,0],[1,4]]
    vector<vector<int>> merge__FALSE1(vector<vector<int>>& intervals) {
        // find end
        int start = 10001, end = -1;
        for (const auto& itvl : intervals) {
            if (itvl[0] < itvl[1]) {
                start = itvl[0] < start ? itvl[0] : start;
                end = itvl[1] - 1 > end ? itvl[1] - 1 : end;
            }
        }

        // 区间i: 端点为[i, i+1]的区间
        int l = end - start + 1;
        vector<int> diff(l, 0);  // l个区间，diff[i]: 区间[i, i+1] - [i-1, i]

        for (const auto& itvl : intervals) {
            if (itvl[0] < itvl[1]) {
                diff[itvl[0] - start]++;
                if (itvl[1] - start < l) {
                    diff[itvl[1] - start]--;
                }
            }
        }

        int state = 0;
        int this_start, a_i_1 = 0;
        vector<vector<int>> res;
        for (int i = start; i <= end; i++) {
            int a_i = a_i_1 + diff[i - start];  // 区间[i, i+1]的值
            a_i_1 = a_i;
            // cout << "# " << i << ": " << a_i << "\n";
            if (0 == state) {
                if (a_i > 0) {
                    this_start = i;
                    state = 1;
                }
            } else {
                if (a_i == 0) {
                    vector<int> merged_interval = {this_start, i};
                    res.emplace_back(merged_interval);
                    state = 0;
                }
            }
        }
        if (1 == state) {
            vector<int> merged_interval = {this_start, end + 1};
            res.emplace_back(merged_interval);
        }

        return res;
    }

    // 以端点为视角是错误的
    vector<vector<int>> merge__FALSE(vector<vector<int>>& intervals) {
        // find end
        int start = 10000, end = 0;
        for (const auto& itvl : intervals) {
            start = itvl[0] < start ? itvl[0] : start;
            end = itvl[1] > end ? itvl[1] : end;
        }
        int l = end - start + 1;
        vector<int> diff(l, 0);
        for (const auto& itvl : intervals) {
            diff[itvl[0] - start]++;
            if (itvl[1] - start + 1 < l) {
                diff[itvl[1] - start + 1]--;
            }
        }

        vector<vector<int>> res;
        int state = 0;
        int this_start;
        int a_i_1 = 0;
        for (int i = start; i <= end; i++) {
            int a_i = a_i_1 + diff[i - start];
            a_i_1 = a_i;
            if (0 == state) {
                if (a_i > 0) {
                    this_start = i;
                    state = 1;
                }
            } else {
                if (a_i == 0) {
                    vector<int> new_itvl = {this_start, i - 1};
                    res.emplace_back(new_itvl);
                    state = 0;
                }
            }
        }
        if (1 == state) {
            vector<int> new_itvl = {this_start, end};
            res.emplace_back(new_itvl);
        }

        return res;
    }

    vector<vector<int>> merge__UNDONE(vector<vector<int>>& intervals) {
        // find end
        int start = 10000, end = 0;
        unordered_set<int> end_set;
        for (const auto& itvl : intervals) {
            start = itvl[0] < start ? itvl[0] : start;
            end = itvl[1] > end ? itvl[1] : end;
            end_set.insert(start);
            end_set.insert(end);
        }
        vector<int> ends;
        for (auto end1 : end_set) {
            ends.emplace_back(end1);
        }
        sort(ends.begin(), ends.end());
        unordered_map<int, int> end_map;
        for (int i = 0; i < ends.size(); i++) {
            end_map[ends[i]] = i;
        }

        vector<int> diff(ends.size(), 0);
        // TODO: base case

        for (const auto& itvl : intervals) {
            diff[end_map[itvl[0]]]++;
            diff[end_map[itvl[1]] + 1]--;
        }
        return {};
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
    vector<vector<int>> intervals;
    vector<vector<int>> res;

    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    res = sol.merge(intervals);
    print_intervals(res);

    intervals = {{1, 4}, {5, 6}};
    res = sol.merge(intervals);
    print_intervals(res);

    return 0;
}