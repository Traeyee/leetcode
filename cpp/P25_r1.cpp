/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-04 11:51
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    // 已保证长度>=k
    tuple<ListNode*, ListNode*, ListNode*> reverse_first_k(ListNode* head,
                                                           int k) {
        ListNode *prev = nullptr, *cur = head, *tmp;
        for (int i = 0; i < k; i++) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return make_tuple(prev, head, cur);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *tail = dummy, *cur = head, *tmp;

        while (cur) {
            int cnt = 0;
            tmp = cur;
            while (tmp && cnt < k) {
                tmp = tmp->next;
                cnt++;
            }
            if (cnt == k) {
                auto sub_res = reverse_first_k(cur, k);
                auto sub_head = get<0>(sub_res), sub_tail = get<1>(sub_res),
                     sub_next = get<2>(sub_res);
                tail->next = sub_head;
                tail = sub_tail;
                cur = tmp;
            } else {
                tail->next = cur;
                break;
            }
        }

        return dummy->next;
    }
};