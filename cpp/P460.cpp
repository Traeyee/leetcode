/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-01 22:50
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

struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val) {
        freq = 1;
        prev = nullptr, next = nullptr;
    }
    void unbind() {
        if (prev) {
            prev->next = next;
        }
        if (next) {
            next->prev = prev;
        }
    }
};

struct DuLinkedList {
    Node *head, *tail;
    DuLinkedList *prev, *next;
    DuLinkedList()
        : head(nullptr), tail(nullptr), prev(nullptr), next(nullptr) {}
    DuLinkedList(Node *node)
        : head(node), tail(node), prev(nullptr), next(nullptr) {}
    void add(Node *node) {
        if (tail) {
            tail->next = node;
        }
        node->prev = tail;
        tail = node;

        if (!head) {
            head = node;
        }
    }
    Node *pop() {
        if (!head) {
            return nullptr;
        }

        auto node = head;
        head = node->next;
        // 仅有一个结点
        if (tail == node) {
            tail = nullptr;
        }
        return node;
    }
    void remove(Node *node) {
        if (head == node) {
            head = node->next;
        }
        if (tail == node) {
            tail = node->prev;
        }
        node->unbind();
    }
};

class LFUCache {
   public:
    LFUCache(int capacity) {}

    int get(int key) {
        if (table_.end() == table_.find(key)) {
            return -1;
        }
    }

    void put(int key, int value) {
        // 先不考虑淘汰的情况
        
    }

   private:
    void update(int key) {
        auto node = table_[key];
        auto old_bucket = buckets_[node->freq];
        node->freq++;
        if (buckets_.end() == buckets_.find(node->freq)) {
            buckets_[node->freq] = new DuLinkedList;
            if (old_bucket->next) {
                old_bucket->next->prev = buckets_[node->freq];
            }
            old_bucket->next = buckets_[node->freq];
        }
        auto new_bucket = buckets_[node->freq];

        old_bucket->remove(node);
        new_bucket->add(node);

        if (!old_bucket->head) {
            if (old_bucket->next) {
                old_bucket->next->prev = old_bucket->prev;
            }
            old_bucket->prev = old_bucket->next;
        }
    }

    DuLinkedList *bucket_head_;
    unordered_map<int, Node *> table_;
    unordered_map<int, DuLinkedList *> buckets_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */