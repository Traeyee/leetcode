/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-01 21:19
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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

class LRUCache {
   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (mapping_.end() == mapping_.find(key)) {
            return -1;
        }
        auto &it = mapping_[key];
        int value = it->second;
        list_.splice(list_.begin(), list_, it);
        return value;
    }

    void put(int key, int value) {
        if (mapping_.end() == mapping_.find(key)) {
            if (mapping_.size() == capacity_) {
                mapping_.erase(list_.back().first);
                list_.pop_back();
            }
            list_.push_front(make_pair(key, value));
            mapping_[key] = list_.begin();
        } else {
            auto &it = mapping_[key];
            it->second = value;
            list_.splice(list_.begin(), list_, it);
        }
    }

    int capacity_;
    typedef pair<int, int> Node;
    map<int, list<Node>::iterator> mapping_;
    list<Node> list_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lru(1);

    return 0;
}