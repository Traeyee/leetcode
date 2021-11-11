// 如果给末尾搞指针，就不用专门存个ignores了
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct SubSolution {
    int num1, num2, num2_idx;
    bool is_solved;
    SubSolution(int n1, int n2, int n2i) : num1(n1), num2(n2), num2_idx(n2i) {
        is_solved = false;
    }
};

class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<SubSolution> subs;
        for (size_t i = 0; i < nums2.size(); i++) {
            subs.emplace_back(-1, nums2[i], i);
        }
        sort(subs.begin(), subs.end(),
             [](SubSolution x1, SubSolution x2) { return x1.num2 > x2.num2; });
        sort(nums1.begin(), nums1.end(), greater<int>());

        int k = 0;
        vector<int> ignores;
        for (const auto& num1 : nums1) {
            bool found = false;
            while (k < subs.size()) {
                if (num1 > subs[k].num2) {
                    found = true;
                    break;
                }
                k++;
            }
            if (found) {
                subs[k].num1 = num1;
                subs[k].is_solved = true;
                k++;
            } else {
                ignores.emplace_back(num1);
            }
        }
        k = 0;
        for (size_t i = 0; i < subs.size(); i++) {
            if (!subs[i].is_solved) {
                subs[i].num1 = ignores[k];
                k++;
            }
        }

        vector<int> new_nums1(nums1.size());
        for (const auto& ele : subs) {
            new_nums1[ele.num2_idx] = ele.num1;
        }

        return new_nums1;
    }
};