/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-06 12:16
 * @brief
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverse_n(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode *new_tail = head, *prev_ptr = nullptr, *cur_ptr = head, *tmp_ptr;
        int cnt = 0;
        while (cnt < n) {
            tmp_ptr = cur_ptr->next;
            cur_ptr->next = prev_ptr;
            prev_ptr = cur_ptr;
            cur_ptr = tmp_ptr;
            cnt++;
        }
        new_tail->next = cur_ptr;
        return prev_ptr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (1 == left) {
            return reverse_n(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};