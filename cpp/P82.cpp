/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 16:04
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *ptr1 = head, *ptr2 = head;

        while (ptr2) {
            if (ptr2->val != ptr1->val) {
                ptr1->next = ptr2;
                ptr1 = ptr1->next;
            }
            ptr2 = ptr2->next;
        }
        ptr1->next = nullptr;

        return head;
    }
};