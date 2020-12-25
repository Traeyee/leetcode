/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   25 December 2020 13:37
 * @brief  
 */

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
      unordered_map<string, vector<string> > key2vec;

      for (const auto &s : strs) {
          // calc key
          vector<char> char_list;
          for (const auto &c : s) {
              char_list.emplace_back(c);
          }
          sort(char_list.begin(), char_list.end());
          string key;
          for (const auto &c : char_list) {
              key.push_back(c);
          }

          // record
          if (key2vec.end() == key2vec.find(key)) {
              vector<string> tmp;
              key2vec[key] = tmp;
          }
          key2vec[key].push_back(s);
      }

      vector<vector<string> > groups;
      for (const auto &p : key2vec) {
          groups.emplace_back(p.second);
      }

      return groups;
  }
};

int main() {
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    s.groupAnagrams(strs);
    return 0;
}