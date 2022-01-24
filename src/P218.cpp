/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-25 15:23
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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (const auto& coord : buildings) {
            min_heap.push(coord[0]);
            min_heap.push(coord[1]);
        }

        vector<int> xs;
        while (min_heap.size() > 0) {
            int x = min_heap.top();
            if (xs.empty() || x != xs.back()) {
                xs.emplace_back(x);
            }
            min_heap.pop();
        }

        vector<int> heights(xs.size() - 1, 0);
        map<int, int> start_indices;
        for (int i = 0; i < xs.size() - 1; i++) {
            start_indices[xs[i]] = i;
        }

        for (const auto& coord : buildings) {
            int left = coord[0], right = coord[1], height = coord[2];
            for (int idx = start_indices[left]; xs[idx] < right; idx++) {
                heights[idx] = height > heights[idx] ? height : heights[idx];
            }
        }

        vector<vector<int>> res;
        int last_x1 = xs[0], last_height = heights[0];
        for (int i = 1; i + 1 < xs.size(); i++) {
            if (heights[i] != last_height) {
                vector<int> sub_res = {last_x1, last_height};
                res.emplace_back(sub_res);
                last_x1 = xs[i];
                last_height = heights[i];
            }
        }
        vector<int> sub_res = {last_x1, last_height};
        res.emplace_back(sub_res);
        sub_res = {xs.back(), 0};
        res.emplace_back(sub_res);

        return res;
    }
};

template <class T>
void print_vector_vector(vector<vector<T>>& nums_vector) {
    for (const auto& nums : nums_vector) {
        cout << '[';
        for (const auto& num : nums) {
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<vector<int>> buildings, res;

    buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    res = sol.getSkyline(buildings);
    print_vector_vector(res);

    buildings = {{0, 2, 3}, {2, 5, 3}};
    res = sol.getSkyline(buildings);
    print_vector_vector(res);

    return 0;
}