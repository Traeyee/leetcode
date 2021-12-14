
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_dummy = new ListNode(0), *even_dummy = new ListNode(0);
        ListNode *odd_ptr = odd_dummy, *even_ptr = even_dummy, *ori_ptr = head;
        int state = 1;
        while (ori_ptr) {
            if (state) {
                odd_ptr->next = ori_ptr;
                odd_ptr = odd_ptr->next;
            } else {
                even_ptr->next = ori_ptr;
                even_ptr = even_ptr->next;
            }
            state ^= 1;
            ori_ptr = ori_ptr->next;
        }
        even_ptr->next = nullptr;
        odd_ptr->next = even_dummy->next;
        return odd_dummy->next;
    }
};

ListNode* linkedlist_from_vector(vector<int> vals) {
    ListNode* dummy = new ListNode;
    ListNode* ptr = dummy;
    for (const auto& val : vals) {
        ptr->next = new ListNode(val);
        ptr = ptr->next;
    }
    return dummy->next;
}

void print_linkedlist(ListNode* head) {
    auto ptr = head;
    while (ptr) {
        cout << ptr->val << ", ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main() {
    Solution sol;
    vector<int> head;
    ListNode* res;

    head = {1, 2, 3, 4, 5};
    res = sol.oddEvenList(linkedlist_from_vector(head));
    print_linkedlist(res);

    return 0;
}