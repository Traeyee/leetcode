/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-02 15:50
 * @brief  得使用双向链表的结构
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

struct Node {
    int val;
    Node *prev, *next;
    Node(int val) : val(val), prev(nullptr), next(nullptr){};
};

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Node* dummy = new Node(0);
        vector<Node*> nodes;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // cout << "#window:";
            // auto tmp_ptr = dummy->next;
            // while (tmp_ptr) {
            //     cout << tmp_ptr->val << ", ";
            //     tmp_ptr = tmp_ptr->next;
            // }
            // cout << "\n";

            if (i - k >= 0) {
                nodes[i - k]->prev->next = nodes[i - k]->next;
                if (nodes[i - k]->next) {
                    nodes[i - k]->next->prev = nodes[i - k]->prev;
                }
            }

            Node *ptr1 = dummy, *ptr2 = dummy->next;
            Node* node = new Node(nums[i]);
            nodes.emplace_back(node);
            while (ptr2 && node->val <= ptr2->val) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            ptr1->next = node;
            node->prev = ptr1;
            node->next = ptr2;
            if (ptr2) {
                ptr2->prev = node;
            }
            if (i >= k - 1) {
                res.emplace_back(dummy->next->val);
            }
        }
        return res;
    }

    vector<int> maxSlidingWindow__FALSE(vector<int>& nums, int k) {
        vector<int> res;
        queue<int> q;

        for (int i = 0; i < k - 1; i++) {
            while (!q.empty()) {
                if (nums[q.front()] < nums[i]) {
                    q.pop();
                } else {
                    break;
                }
            }
            q.push(i);
        }

        int l_end, r_end;  // both close
        for (l_end = 0; l_end + k <= nums.size(); l_end++) {
            r_end = l_end + k - 1;
            while (!q.empty()) {
                cout << "#db1:" << l_end << "," << r_end << ":"
                     << nums[q.front()] << "?" << nums[r_end]
                     << ", q=" << q.size() << "\n";
                if (q.front() == l_end - 1 || nums[q.front()] < nums[r_end]) {
                    cout << "#pop:" << l_end << "," << r_end << ":"
                         << nums[q.front()] << "\n";
                    q.pop();
                } else {
                    break;
                }
            }
            q.push(r_end);
            res.emplace_back(nums[q.front()]);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution s;
    for (const auto& ele : s.maxSlidingWindow(nums, k)) {
        cout << ele << ", ";
    }
    cout << "\n";

    nums = {1, 3, 1, 2, 0, 5};
    k = 3;
    for (const auto& ele : s.maxSlidingWindow(nums, k)) {
        cout << ele << ", ";
    }
    cout << "\n";

    return 0;
}