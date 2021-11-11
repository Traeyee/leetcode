// 递归能更简洁
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0, head);
        ListNode *last_node = dummy, *cur_node = head;
        while (cur_node) {
            int i = 1;
            ListNode* last_ptr = cur_node;
            while (i < k) {
                if (!last_ptr->next) {
                    break;
                }
                last_ptr = last_ptr->next;
                i++;
            }
            if (i == k) {
                // 可以做翻转
                ListNode *new_head = nullptr, *cur_ptr = cur_node, *tmp_ptr;
                while (new_head != last_ptr) {
                    tmp_ptr = cur_ptr;
                    cur_ptr = cur_ptr->next;
                    tmp_ptr->next = new_head;
                    new_head = tmp_ptr;
                }
                last_node->next = new_head;
                cur_node->next = cur_ptr;

                last_node = cur_node;
                cur_node = last_node->next;
            } else {
                break;
            }
        }

        return dummy->next;
    }
};