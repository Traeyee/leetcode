/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-05 09:59
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = 0, len_b = 0;
        ListNode *ptr1 = headA;
        while (ptr1) {
            len_a++;
            ptr1 = ptr1->next;
        }
        ptr1 = headB;
        while (ptr1) {
            len_b++;
            ptr1 = ptr1->next;
        }
        ListNode* ptr2;
        int d;
        if (len_a > len_b) {
            ptr1 = headA;
            ptr2 = headB;
            d = len_a - len_b;
        } else {
            ptr1 = headB;
            ptr2 = headA;
            d = len_b - len_a;
        }

        while (d > 0) {
            ptr1 = ptr1->next;
            d--;
        }
        while (ptr1 && ptr2 && ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};