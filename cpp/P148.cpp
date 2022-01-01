/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 22:42
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (slow != fast && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        auto part1 = sortList(head);
        auto part2 = sortList(mid);

        // merge
        ListNode *dummy = new ListNode, *cur_ptr;
        cur_ptr = dummy;
        while (part1 && part2) {
            if (part1->val < part2->val) {
                cur_ptr->next = part1;
                part1 = part1->next;
            } else {
                cur_ptr->next = part2;
                part2 = part2->next;
            }
            cur_ptr = cur_ptr->next;
        }
        if (part1) {
            cur_ptr->next = part1;
        }
        if (part2) {
            cur_ptr->next = part2;
        }
        return dummy->next;
    }

    // TL，因为我这个算法没有实现随机化
    tuple<ListNode*, ListNode*, ListNode*> partition(ListNode* head) {
        // cout << "# " << head->val << "\n";
        ListNode *lhead = new ListNode(0), *guard = head,
                 *rhead = new ListNode(0);
        ListNode *ltail = lhead, *rtail = rhead;
        ListNode* ptr = head->next;

        while (ptr) {
            // cout << ptr->val << "\n";
            if (ptr->val < guard->val) {
                ltail->next = ptr;
                ltail = ltail->next;
            } else {
                rtail->next = ptr;
                rtail = rtail->next;
            }
            ptr = ptr->next;
        }
        ltail->next = nullptr;
        rtail->next = nullptr;

        auto res = make_tuple(lhead->next, guard, rhead->next);
        return res;
    }

    // 不能传空
    pair<ListNode*, ListNode*> quicksort(ListNode* head) {
        // cout << head->val << "\n";
        // partition得3parts
        // quicksort(part1)得头尾，相连
        auto t = partition(head);
        ListNode *lpart = get<0>(t), *guard = get<1>(t), *rpart = get<2>(t);
        ListNode *new_head = guard, *new_tail = guard;
        if (lpart) {
            auto lp = quicksort(lpart);
            lp.second->next = guard;
            new_head = lp.first;
        }
        if (rpart) {
            auto rp = quicksort(rpart);
            guard->next = rp.first;
            new_tail = rp.second;
        }
        new_tail->next = nullptr;
        auto res = make_pair(new_head, new_tail);
        return res;
    }
    ListNode* sortList__TL(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        auto res = quicksort(head);
        return res.first;
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
    ListNode *node, *res;
    vector<int> head;

    head = {4, 2, 1, 3};
    node = linkedlist_from_vector(head);
    res = sol.sortList(node);
    print_linkedlist(res);

    head = {-1, 5, 3, 4, 0};
    node = linkedlist_from_vector(head);
    res = sol.sortList(node);
    print_linkedlist(res);

    return 0;
}