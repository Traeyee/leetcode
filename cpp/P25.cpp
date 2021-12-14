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
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur_node = head, *ptr, *prev_ptr, *cur_ptr, *tmp_ptr, *last_node = dummy;
        while (cur_node) {
            // 看看够不够k个
            int cnt = 0;
            ptr = cur_node;
            while (ptr && cnt < k) {
                ptr = ptr->next;
                cnt++;
            }
            // 结束时ptr指向下一个起点
            if (k == cnt) {
                // 够，翻转，并使last_node->next指向新head，last_node=新tail
                prev_ptr = nullptr, cur_ptr = cur_node;
                cnt = 0;
                while (cnt < k) {
                    tmp_ptr = cur_ptr->next;
                    cur_ptr->next = prev_ptr;
                    prev_ptr = cur_ptr;
                    cur_ptr = tmp_ptr;
                    cnt++;
                }
                // 结束时prev_ptr指向新head，cur_ptr是下一轮的起点
                last_node->next = prev_ptr;
                cur_node->next = cur_ptr;
                last_node = cur_node;
                cur_node = cur_ptr;
            } else {
                // 不够，break
                break;
            }
        }
        return dummy->next;
    }
    ListNode* reverseKGroup0(ListNode* head, int k) {
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