#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
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
    bool isPalindrome(ListNode* head) {
        
    }
    pair<bool, int> traverse(ListNode* head) {
        auto res = traverse(head->next);
        return make_pair(res.first && (res.second == head->val), head->val);
    }
    bool isPalindrome__FALSE(ListNode* head) {
        stack<int> stk;
        auto p = head;
        while (p) {
            stk.push(p->val);
            p = p->next;
        }
        p = head;
        while (!stk.empty()) {
            int x = stk.top();
            if (x != p->val) {
                return false;
            }
            stk.pop();
            p = p->next;
        }
        return true;
    }
};