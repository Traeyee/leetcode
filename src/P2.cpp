/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-05 10:28
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode;
        ListNode *ptr1 = l1, *ptr2 = l2, *ptr3 = dummy;
        int x1, x2, carry = 0;
        while (ptr1 || ptr2 || carry) {
            if (ptr1) {
                x1 = ptr1->val;
                ptr1 = ptr1->next;
            } else {
                x1 = 0;
            }
            if (ptr2) {
                x2 = ptr2->val;
                ptr2 = ptr2->next;
            } else {
                x2 = 0;
            }
            int sum = x1 + x2 + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ptr3->next = new ListNode(sum);
            ptr3 = ptr3->next;
        }

        return dummy->next;
    }
};