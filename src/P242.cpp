/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   01 January 2021 19:55
 * @brief  
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
  bool isAnagram(string s, string t) {
      vector<char> vec;
      for (auto c : s) {
          vec.push_back(c);
      }
      sort(vec.begin(), vec.end());
      string key1;
      for (auto c : vec) {
          key1.push_back(c);
      }

      vec.clear();
      for (auto c : t) {
          vec.push_back(c);
      }
      sort(vec.begin(), vec.end());
      string key2;
      for (auto c : vec) {
          key2.push_back(c);
      }

      return key1 == key2;
  }
};