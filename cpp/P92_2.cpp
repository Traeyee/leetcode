#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* _reverseBetween(ListNode* last_node, ListNode* cur_node, int left,
                              int right) {
        if (left == right) {
            return cur_node;
        } else if (left > 1) {
            cur_node->next =
                _reverseBetween(cur_node, cur_node->next, left - 1, right - 1);
            return cur_node;
        } else if (right > 0) {
            auto tmp_ptr = cur_node->next;
            cur_node->next = last_node;
            return _reverseBetween(cur_node, tmp_ptr, left - 1, right - 1);
        } else {
            auto tmp_ptr = last_node;
            int k = left;
            while (k < 0) {
                k++;
                tmp_ptr = tmp_ptr->next;
            }
            tmp_ptr->next = cur_node;
            return last_node;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return _reverseBetween(nullptr, head, left, right);
    }
};