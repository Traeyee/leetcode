/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   12 November 2020 14:26
 * @brief  要多练习快排
 */
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void qsort(vector<pair<char, int> > &items, int lbound, int rbound) {
      if (lbound >= rbound) {
          return;
      }
      int guard = items[lbound].second;
      int p1 = lbound;
      int p2 = lbound;
      while (p2 < rbound - 1) {
          p2++;
          if (items[p2].second > guard) {
              p1++;
              if (p1 < p2) {
                  auto tmp = items[p1];
                  items[p1] = items[p2];
                  items[p2] = tmp;
              }
          }
      }
      if (lbound < p1) {
          auto tmp = items[p1];
          items[p1] = items[lbound];
          items[lbound] = tmp;
      }
      qsort(items, lbound, p1);
      qsort(items, p1 + 1, rbound);
  }

  string frequencySort(string s) {
      unordered_map<char, int> counter;

      for (const auto &c : s) {
          if (counter.find(c) == counter.end()) {
              counter[c] = 0;
          }
          counter[c]++;
      }

      vector<pair<char, int> > items;
      items.reserve(counter.size());
      for (const auto &p : counter) {
          items.emplace_back(p);
      }

      qsort(items, 0, items.size());
      string ret;
      for (const auto &p : items) {
          for (size_t i = 0; i < p.second; i++) {
              ret.push_back(p.first);
          }
      }

      return ret;
  }
};

int main() {
    Solution s;
    cout << s.frequencySort("tree") << std::endl;
    cout << s.frequencySort("cccaaa") << std::endl;
    cout << s.frequencySort("Aabb") << std::endl;
    cout << s.frequencySort("2a554442f544asfasssffffasss") << std::endl;

    return 0;
}