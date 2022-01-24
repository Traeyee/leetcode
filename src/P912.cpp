/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 15:59
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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
    vector<int> quick_sort_r1(vector<int>& nums) {
        stack<pair<int, int>> stk;
        stk.emplace(0, nums.size() - 1);

        while (stk.size() > 0) {
            int l = stk.top().first, r = stk.top().second;
            stk.pop();
            if (l >= r) {
                continue;
            }

            int mid = (r - l) / 2 + l;
            swap(nums[l], nums[mid]);
            int n_l = 0;
            for (int i = l + 1; i <= r; i++) {
                if (nums[i] < nums[l]) {
                    int r_start = l + 1 + n_l;
                    swap(nums[i], nums[r_start]);
                    n_l++;
                }
            }
            int l_end = l + n_l;
            swap(nums[l], nums[l_end]);
            stk.emplace(l, l_end);
            stk.emplace(l_end + 1, r);
        }

        return nums;
    }

    vector<int> merge_sort(vector<int>& nums) {
        _merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void _merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (r - l) / 2 + l;
        _merge_sort(nums, l, mid);
        _merge_sort(nums, mid + 1, r);

        vector<int> tmp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                tmp.emplace_back(nums[i]);
                i++;
            } else {
                tmp.emplace_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            tmp.emplace_back(nums[i]);
            i++;
        }
        while (j <= r) {
            tmp.emplace_back(nums[j]);
            j++;
        }

        for (i = 0; i < tmp.size(); i++) {
            nums[l + i] = tmp[i];
        }
    }

    vector<int> quick_sort(vector<int>& nums) {
        stack<pair<int, int>> stk;
        stk.emplace(0, nums.size() - 1);
        while (stk.size() > 0) {
            int l = stk.top().first, r = stk.top().second;
            stk.pop();

            // 加入随机化因素，避免worst case
            int mid = (l + r) / 2;
            swap(nums[mid], nums[l]);

            int guard = nums[l];
            int n_l = 0, n_r = 0;
            for (int i = l + 1; i <= r; i++) {
                int start_r = l + 1 + n_l;
                if (nums[i] < guard) {
                    if (n_r > 0) {
                        swap(nums[i], nums[start_r]);
                    }
                    n_l++;
                } else {
                    n_r++;
                }
            }
            int end_l = l + n_l;
            swap(nums[l], nums[end_l]);

            if (n_l > 1) {
                stk.emplace(l, end_l - 1);
            }
            if (n_r > 1) {
                stk.emplace(l + n_l + 1, r);
            }
        }

        return nums;
    }

    vector<int> bubble_sort(vector<int>& nums) {
        int tmp;
        for (int rbound = nums.size(); rbound > 0; rbound--) {
            for (size_t i = 0; i + 1 < rbound; i++) {
                if (nums[i] > nums[i + 1]) {
                    tmp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = tmp;
                }
            }
        }
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) { return quick_sort_r1(nums); }
};

int main() {
    vector<int> nums = {5, 2, 3, 1};
    Solution s;
    for (const auto& ele : s.sortArray(nums)) {
        cout << ele << ", ";
    }
    cout << "\n";

    nums = {5, 1, 1, 2, 0, 0};
    for (const auto& ele : s.sortArray(nums)) {
        cout << ele << ", ";
    }
    cout << "\n";
    return 0;
}