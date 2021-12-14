/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 21:24
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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *slow_ptr = head, *fast_ptr = head->next;
        while (fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr) {
                return true;
            }
        }
        return false;
    }
};