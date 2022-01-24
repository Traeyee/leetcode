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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int k = 1;
        ListNode *new_head = head, *next_node, *tmp_ptr, *new_tail, *old_tail,
                 *dummy;
        dummy = new ListNode(0, head);
        old_tail = dummy;
        while (k < left) {
            k++;
            old_tail = new_head;
            new_head = new_head->next;
        }
        new_tail = new_head;
        next_node = new_head->next;
        while (k < right) {
            k++;
            tmp_ptr = next_node;
            next_node = next_node->next;
            tmp_ptr->next = new_head;
            new_head = tmp_ptr;
        }

        old_tail->next = new_head;
        new_tail->next = next_node;

        return dummy->next;
    }
};