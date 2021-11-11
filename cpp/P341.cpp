#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
   public:
    void _relax(const vector<NestedInteger> &nestedList) {
        for (const auto &ele : nestedList) {
            if (ele.isInteger()) {
                _flat_list->emplace_back(ele.getInteger());
            } else {
                _relax(ele.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        _flat_list = new vector<int>;
        _it_ptr = 0;
        _relax(nestedList);
    }

    int next() {
        int ret = (*_flat_list)[_it_ptr];
        _it_ptr++;
        return ret;
    }

    bool hasNext() {
        return _it_ptr < _flat_list->size();
    }

    int _it_ptr;
    vector<int> *_flat_list;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */