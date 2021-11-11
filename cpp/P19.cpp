/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-10 10:49
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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *ptr1 = dummy, *ptr2 = dummy, *last_ptr2;
        for (int i = 0; i < n; i++) {
            ptr1 = ptr1->next;
        }
        while (ptr1) {
            ptr1 = ptr1->next;
            last_ptr2 = ptr2;
            ptr2 = ptr2->next;
        }
        last_ptr2->next = ptr2->next;

        return dummy->next;
    }
};