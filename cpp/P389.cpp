/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   02 January 2021 17:24
 * @brief  说实话，本质上就是找出现那一题
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
      int bits = 0;
      for (auto c : s + t) {
          bits ^= int(c);
      }
      return char(bits);
  }
};

int main() {
    string s = "abcd", t = "abcde";
    Solution sol;
    cout << sol.findTheDifference(s, t);
}