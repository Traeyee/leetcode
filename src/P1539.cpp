/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-12 16:39
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
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int seq = 0;
        while (k > 0 && i < arr.size()) {
            seq++;
            if (seq == arr[i]) {
                i++;
                k++;
            }
            k--;
        }
        while (k > 0) {
            seq++;
            k--;
        }

        return seq;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int k;

    arr = {2, 3, 4, 7, 11}, k = 5;
    cout << sol.findKthPositive(arr, k) << '\n';

    arr = {1, 2, 3, 4}, k = 2;
    cout << sol.findKthPositive(arr, k) << '\n';

    return 0;
}