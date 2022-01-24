/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-25 10:22
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
    int select_kth(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int n_lpart = 0;
            for (int i = l; i <= r; i++) {
                if (nums[i] < nums[l]) {
                    int rpart_start = l + 1 + n_lpart;
                    swap(nums[rpart_start], nums[i]);
                    n_lpart++;
                }
            }
            int lpart_end = l + n_lpart;
            swap(nums[l], nums[lpart_end]);
            if (lpart_end + 1 < k) {
                l = lpart_end + 1;
            } else if (lpart_end + 1 > k) {
                r = lpart_end - 1;
            } else {
                return nums[lpart_end];
            }
        }

        return 0;
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        int k = (n + 1) / 2;
        int mid = select_kth(nums, k);
        int n_lpart = 0, n_midpart = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mid) {
                int rpart_start = n_lpart + n_midpart;
                swap(nums[i], nums[rpart_start]);
                int midpart_start = n_lpart;
                swap(nums[rpart_start], nums[midpart_start]);
                n_lpart++;
            } else if (nums[i] == mid) {
                int rpart_start = n_lpart + n_midpart;
                swap(nums[i], nums[rpart_start]);
                n_midpart++;
            }
        }

        vector<int> tmp;
        int i = k - 1, j = n - 1;
        while (i >= 0) {
            tmp.emplace_back(nums[i]);
            i--;
            if (j >= k) {
                tmp.emplace_back(nums[j]);
                j--;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = tmp[i];
        }
    }

    void wiggleSort__NAIVE(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        sort(nums.begin(), nums.end());

        int j = n - 1;
        int i = (n - 1) / 2;
        vector<int> res;
        // 教训：无符号数与负数不要比较
        while (res.size() + 2 <= n) {
            res.emplace_back(nums[i]);
            res.emplace_back(nums[j]);
            i--;
            j--;
        }
        if (n % 2 == 1) {
            res.emplace_back(nums[0]);
        }
        swap(nums, res);
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
    vector<int> nums;

    nums = {1, 5, 1, 1, 6, 4};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {1, 3, 2, 2, 3, 1};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {4, 5, 5, 6};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {1};
    sol.wiggleSort(nums);
    print_vector(nums);

    return 0;
}