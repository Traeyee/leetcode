/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-06 10:57
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

// 观察事实：第一个重复必是新开头
// 序列选择，同结尾选最短，同结尾的，先构一定比后构长

struct Sequence {
    int n, tail;
    Sequence(int tail) : n(1), tail(tail) {}
    void append() {
        n++;
        tail++;
    }
};

class Solution {
   public:
    bool isPossible(vector<int>& nums) {
        stack<Sequence> stk1, stk2;

        int x;

        if (stk1.size() > 0) {
            // 假设stk1有货
            if (x == stk1.top().tail + 1) {
                stk1.top().append();
            } else if (x == stk1.top().tail) {
                auto seq = stk1.top();
                stk2.push(seq);
                stk1.pop();
            }
        } else {
            
        }
    }
};