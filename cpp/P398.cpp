/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   05 January 2021 13:46
 * @brief  好像并不是蓄水池问题？注意当我们限制循环次数，便是个已知序列？确实是蓄水池问题，先将池灌满
 * 教训1：详见test_cpp.cpp:test_reserve
 * 教训2：uniform_int_distribution: [a, b]; uniform_real_distribution: [a, b)
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 经典随机数算法，用于C11前
// return a random integer in the range [0, n)
int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);
    return r;
}

class Solution {
 public:
  Solution(vector<int> &nums) {
      nums_ = &nums;
  }
  vector<int> pickK(int target, int k) {
      vector<int> pool(0);
      std::random_device rd;
      std::mt19937 mt(rd());

      vector<int> &nums = *nums_;
      int n = 0;
      for (int i = 0; i < nums.size(); i++) {
          if (nums[i] == target) {
              n++;
              if (pool.size() < k) {
                  pool.push_back(i);
              } else {  // 抽样替换，使得p = k / n
                  // 相当于从n中再选一次
                  std::uniform_int_distribution<int> dist(0, n - 1);
                  int m = dist(mt);
                  if (m < k) {
                      pool[m] = i;
                  }
              }
          }
      }

      return pool;
  }

  int pick(int target) {
      return pickK(target, 1)[0];
  }

  vector<int> *nums_;
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution s(nums);
    unordered_map<int, int> counter;
    for (int i = 0; i < 10000; i++) {
        auto idx = s.pick(3);
        if (counter.end() == counter.find(idx)) {
            counter[idx] = 0;
        }
        counter[idx]++;
    }

    for (const auto &p : counter) {
        cout << p.first << ":" << p.second << "\n";
    }
}