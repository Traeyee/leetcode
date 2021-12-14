/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 12:10
 * @brief  实际就是蓄水池问题
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

random_device rd;
mt19937 mt(rd());

// k个，对于i，在[0, i]区间上取一点p，若p < k，则替换第p池的元素
class Solution {
   public:
    Solution(ListNode* head) {
        head_ = head;
        ptr_ = head;
        pick_ = head->val;
        n_ = 1;
    }

    // 这个就是baseline解法
    // 对于t时刻，每个元素被选择的概率都是1/n
    int getRandom() {
        int pick;
        int i = 1;
        auto ptr = head_;
        while (ptr) {
            uniform_int_distribution<> dist(1, i);
            int r = dist(mt);
            if (r == i) {
                pick = ptr->val;
            }
            i++;
            ptr = ptr->next;
        }
        return pick;
    }

    // 为什么这个会错？
    // 对于t时刻，跟链表现在的位置有关，反正不对
    int getRandom__FALSE() {
        ptr_ = ptr_->next ? ptr_->next : head_;
        n_++;

        double p = 1 / n_;
        uniform_real_distribution<> real_dist(0, 1);
        double point = real_dist(mt);
        // cout << point << "\t?\t" << p << "\n";
        // cout << p << "\n";
        if (point < p) {
            pick_ = ptr_->val;
        }
        return pick_;
    }

    int pick_;
    double n_;
    ListNode *head_, *ptr_;
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

void run_example(vector<int>& nums) {
    auto head = linkedlist_from_vector(nums);
    Solution sol(head);
    unordered_map<int, int> counter;
    for (int i = 0; i < 1000; i++) {
        auto ele = sol.getRandom();
        counter[ele]++;
    }
    for (const auto& p : counter) {
        cout << p.first << ": " << p.second << "\n";
    }
    cout << "\n";
}

int main() {
    vector<int> nums;

    nums = {1, 2, 3};
    run_example(nums);

    nums = {11, 12};
    run_example(nums);

    return 0;
}