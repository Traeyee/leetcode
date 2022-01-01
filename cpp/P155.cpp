/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-29 22:55
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

class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        val_stack_.push(val);
        if (min_stack_.size() > 0) {
            int min_val = val < min_stack_.top() ? val : min_stack_.top();
            min_stack_.push(min_val);
        } else {
            min_stack_.push(val);
        }
    }

    void pop() {
        val_stack_.pop();
        min_stack_.pop();
    }

    int top() { return val_stack_.top(); }

    int getMin() { return min_stack_.top(); }

   private:
    stack<int> val_stack_;
    stack<int> min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */