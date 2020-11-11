/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   12 November 2020 00:08
 * @brief  
 */
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
      ListNode *new_head = nullptr;
      ListNode *tmp_ptr = nullptr;
      ListNode *cur_ptr = head;
      while (cur_ptr) {
          tmp_ptr = cur_ptr->next;
          cur_ptr->next = new_head;
          new_head = cur_ptr;
          cur_ptr = tmp_ptr;
      }
      return new_head;
  }
};

int main() {
    Solution s;
    ListNode *x = new ListNode(1);
    x->next = new ListNode(2);
    x->next->next = new ListNode(3);
    ListNode *y = s.reverseList(x);
    ListNode* tmp_ptr = y;
    while (tmp_ptr) {
        std::cout << tmp_ptr->val << std::endl;
        tmp_ptr = tmp_ptr->next;
    }
    return 0;
}