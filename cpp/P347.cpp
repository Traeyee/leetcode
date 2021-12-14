/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   13 November 2020 09:21
 * @brief
 */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int val, freq;
    Node *prev, *next;
    Node(int val) : val(val), freq(0), prev(nullptr), next(nullptr){};
    void link(Node *prev1, Node *next1) {
        if (prev1) {
            prev1->next = this;
        }
        if (next1) {
            next1->prev = this;
        }
        prev = prev1, next = next1;
    }
    void detach() {
        if (prev) {
            prev->next = next;
        }
        if (next) {
            next->prev = prev;
        }
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, Node *> freq2head;
        unordered_map<int, Node *> freq2tail;
        unordered_map<int, Node *> node_map;
        int max_freq = 0;

        for (int x : nums) {
            if (node_map.end() == node_map.find(x)) {
                node_map[x] = new Node(x);
            }
            auto node = node_map[x];
            if (node->freq > 0) {
                if (freq2head[node->freq] == node) {
                    freq2head[node->freq] = node->next;
                }
                if (freq2tail[node->freq] == node) {
                    freq2tail[node->freq] = node->prev;
                }
            }
            node->detach();

            node->freq++;
            if (freq2head.end() == freq2head.find(node->freq)) {
                freq2head[node->freq] = nullptr;
                freq2tail[node->freq] = nullptr;
            }
            if (!freq2head[node->freq]) {
                freq2head[node->freq] = node;
                freq2tail[node->freq] = node;
            } else {
                node->link(freq2tail[node->freq], nullptr);
                freq2tail[node->freq] = node;
            }
            max_freq = node->freq > max_freq ? node->freq : max_freq;
        }
        // cout << "#here\n";
        vector<int> res;
        int freq1 = max_freq;
        while (1) {
            auto ptr = freq2head[freq1];
            while (ptr) {
                // cout << ptr->val << '\n';
                res.emplace_back(ptr->val);
                ptr = ptr->next;
                if (res.size() == k) {
                    return res;
                }
            }
            // cout << freq1 << '\n';
            freq1--;
        }
        return res;
    }

    // 垃圾版本
    vector<int> topKFrequent0(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (const auto &x : nums) {
            if (counter.find(x) == counter.end()) {
                counter[x] = 0;
            }
            counter[x]++;
        }

        typedef pair<int, int> intp;
        auto cmp = [](intp &p1, intp &p2) { return p1.second < p2.second; };
        priority_queue<intp, vector<intp>, decltype(cmp)> items(cmp);
        for (const auto &p : counter) {
            items.push(p);
        }

        vector<int> ret;
        while (!items.empty()) {
            auto p = items.top();
            items.pop();
            ret.emplace_back(p.first);
            if (ret.size() == k) {
                break;
            }
        }

        return ret;
    }
};

template <class T>
void print_vector(vector<T> &nums) {
    for (const auto &num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums;
    int k;
    vector<int> res;

    nums = {1, 1, 1, 2, 2, 3}, k = 2;
    res = sol.topKFrequent(nums, k);
    print_vector(res);

    nums = {1}, k = 1;
    res = sol.topKFrequent(nums, k);
    print_vector(res);

    nums = {3, 2, 3, 1,  2,  4, 5, 5, 6, 7, 7, 8, 2, 3,
            1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6},
    k = 10;
    res = sol.topKFrequent(nums, k);
    print_vector(res);

    return 0;
}