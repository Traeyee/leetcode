/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-23 22:25
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
    struct Element {
        int val, idx;
        Element(int val, int idx) : val(val), idx(idx) {}
    };

    void merge_sort(vector<Element>& eles, int l, int r, vector<int>& res) {
        if (l >= r) {
            return;
        }

        int mid = (r - l) / 2 + l;
        merge_sort(eles, l, mid, res);
        merge_sort(eles, mid + 1, r, res);

        // merge
        // vector<int> nums2;
        vector<Element> eles2;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (eles[i].val <= eles[j].val) {
                // nums2.emplace_back(eles[i].val);
                eles2.emplace_back(eles[i]);

                res[eles[i].idx] += j - (mid + 1);

                i++;
            } else {
                // nums2.emplace_back(eles[j].val);
                eles2.emplace_back(eles[j]);
                j++;

                // for (int i1 = i; i1 <= mid; i1++) {
                //     res[eles[i1].idx]++;
                // }
            }
        }
        while (i <= mid) {
            // nums2.emplace_back(eles[i].val);
            eles2.emplace_back(eles[i]);

            res[eles[i].idx] += r - mid;

            i++;
        }
        while (j <= r) {
            // nums2.emplace_back(eles[j].val);
            eles2.emplace_back(eles[j]);
            j++;
        }

        for (int i = l; i <= r; i++) {
            eles[i] = eles2[i - l];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Element> eles;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            eles.emplace_back(nums[i], i);
        }
        merge_sort(eles, 0, n - 1, res);

        return res;
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums, res;

    nums = {5, 2, 6, 1};
    res = sol.countSmaller(nums);
    print_vector(res);

    nums = {-1};
    res = sol.countSmaller(nums);
    print_vector(res);

    nums = {-1, -1};
    res = sol.countSmaller(nums);
    print_vector(res);

    return 0;
}