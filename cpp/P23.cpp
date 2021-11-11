/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-10 17:37
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 教训：最小堆用较大函数，最大堆用较小函数
        auto cmp = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };
        // see
        // https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(
            cmp);

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                min_heap.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode;
        ListNode* ptr = dummy;
        while (min_heap.size() > 0) {
            // cout << "#here\n";
            // 教训：指针容器就不要用&了
            auto node = min_heap.top();
            ptr->next = node;
            ptr = ptr->next;
            min_heap.pop();
            if (node->next) {
                // cout << node->val << ", " << node->next->val << "\n";
                min_heap.push(node->next);
            }
        }

        return dummy->next;
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

vector<ListNode*> construct_linkedlist_list(vector<vector<int>> ll) {
    vector<ListNode*> res;
    for (const auto& l : ll) {
        res.emplace_back(linkedlist_from_vector(l));
    }
    return res;
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
    vector<vector<int>> lists;
    vector<ListNode*> lists1;

    lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    lists1 = construct_linkedlist_list(lists);
    print_linkedlist(sol.mergeKLists(lists1));

    lists = {{}};
    lists1 = construct_linkedlist_list(lists);
    print_linkedlist(sol.mergeKLists(lists1));

    return 0;
}