/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-08 21:01
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
    void reverse_arr(vector<int>& arr, int k) {
        int l = 0, r = k - 1;
        while (l < r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == i + 1) {
                continue;
            }
            for (int j = i - 1; j >= 1; j--) {
                if (arr[j] == i + 1) {
                    res.emplace_back(j + 1);
                    reverse_arr(arr, j + 1);
                    break;
                }
            }
            res.emplace_back(i + 1);
            reverse_arr(arr, i + 1);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {3, 2, 4, 1};
    sol.pancakeSort(arr);
    for (auto ele : arr) {
        cout << ele << ", ";
    }
    cout << "\n";

    arr = {1, 2, 3};
    sol.pancakeSort(arr);
    for (auto ele : arr) {
        cout << ele << ", ";
    }
    cout << "\n";

    return 0;
}