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

    ListNode* reverseBetween0(ListNode* head, int left, int right) {
        return _reverseBetween(nullptr, head, left, right);
    }

    ListNode* reverseBetween__FALSE(ListNode* head, int left, int right) {
        if (!head) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *tail1, *head2, *tail2, *head3, *ptr = dummy;
        
        int seq = 1;
        while (seq < left) {
            ptr = ptr->next;
            seq++;
        }
        tail1 = ptr;
        head2 = ptr->next;
        while (seq <= right) {
            ptr = ptr->next;
            seq++;
        }
        tail2 = ptr;
        head3 = ptr->next;

        // 反转
        ListNode *new_head2 = nullptr, *new_tail2 = head2, *tmp_ptr;
        ptr = head2;
        while (ptr != head3) {
            tmp_ptr = ptr->next;
            ptr->next = new_head2;
            new_head2 = ptr;
            ptr = tmp_ptr;
        }
        new_tail2 = ptr;
        tail1->next = new_head2;
        new_tail2->next = head3;

        return dummy->next;
    }
};