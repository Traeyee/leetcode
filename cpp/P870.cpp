// 如果给末尾搞指针，就不用专门存个ignores了
// 思路：搞定能搞定的
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

struct SSol {
    int num1, num2, idx2;
    bool solved;
    SSol(int num2, int idx2) : num2(num2), idx2(idx2), solved(false) {}
};

// 没来得及写：可以这样，1由大到小排序，2由大到小排序，对于i, 若n1[i] >
// n2[i]，加入，否则找n1最小的顶
//

class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<SSol> ssol2;
        for (int i = 0; i < n; i++) {
            ssol2.emplace_back(nums2[i], i);
        }
        auto cmp = [](SSol& x1, SSol& x2) {return x1.num2 < x2.num2;};
        sort(ssol2.begin(), ssol2.end(), cmp);
        sort(nums1.begin(), nums1.end());
        vector<bool> used(n, false);
        
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (nums1[i] > ssol2[j].num2) {
                ssol2[j].num1 = nums1[i];
                ssol2[j].solved = true;
                used[i] = true;
                j++;
            }
            i++;
        }
        i = 0;
        for (auto& s2 : ssol2) {
            if (s2.solved) {
                continue;
            }
            while (used[i]) {
                i++;
            }
            s2.num1 = nums1[i];
            used[i] = true;
        }
        vector<int> res(n);
        for (auto& s2 : ssol2) {
            res[s2.idx2] = s2.num1;
        }
        return res;
    }
    vector<int> advantageCount__TL(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<bool> used(n, false);

        vector<bool> found(n, false);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[j] && nums1[j] > nums2[i]) {
                    res[i] = nums1[j];
                    used[j] = true;
                    found[i] = true;
                    break;
                }
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!found[i]) {
                while (used[j]) {
                    j++;
                }
                res[i] = nums1[j];
                used[j] = true;
                found[i] = true;
                j++;
            }
        }

        return res;
    }
    vector<int> advantageCount0(vector<int>& nums1, vector<int>& nums2) {
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

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums1, nums2, res;

    nums1 = {2, 7, 11, 15}, nums2 = {1, 10, 4, 11};
    res = sol.advantageCount(nums1, nums2);
    print_vector(res);

    nums1 = {12, 24, 8, 32}, nums2 = {13, 25, 32, 11};
    res = sol.advantageCount(nums1, nums2);
    print_vector(res);

    return 0;
}