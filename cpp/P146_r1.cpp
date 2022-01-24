/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-09 14:50
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

struct KV {
    int key, value;
    KV(int key, int value) : key(key), value(value) {}
};

class LRUCache {
   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (!map_.count(key)) {
            return -1;
        }
        auto it = map_[key];
        list_.splice(list_.begin(), list_, it);
        return (*it).value;
    }

    void put(int key, int value) {
        if (map_.count(key)) {
            auto it = map_[key];
            (*it).value = value;
            list_.splice(list_.begin(), list_, it);
        } else {
            if (map_.size() == capacity_) {
                auto& kv0 = list_.back();
                // 教训：先erase后pop_back
                map_.erase(kv0.key);
                list_.pop_back();
            }
            KV kv(key, value);
            list_.push_front(kv);
            auto it = list_.begin();
            map_[key] = it;
        }
    }

   private:
    int capacity_;
    map<int, list<KV>::iterator> map_;
    list<KV> list_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */