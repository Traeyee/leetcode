/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-07 10:01
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

class Solution {
   public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();

        int tail_zeroes = 0;
        string res("0");
        int carry;
        for (int i = n1 - 1; i >= 0; i--) {
            carry = 0;
            stack<char> stk;
            for (int j = n2 - 1; j >= 0; j--) {
                int x = (num1[i] - '0') * (num2[j] - '0') + carry;
                if (x >= 10) {
                    carry = x / 10;
                    x %= 10;
                } else {
                    carry = 0;
                }
                stk.push(x + '0');
            }
            if (carry > 0) {
                stk.push(carry + '0');
            }
            string tmp;
            while (stk.size() > 0) {
                tmp.push_back(stk.top());
                stk.pop();
            }
            for (int j = 0; j < tail_zeroes; j++) {
                tmp.push_back('0');
            }
            tail_zeroes++;
            res = add(res, tmp);
        }
        // carry不会超过10
        if (carry > 0) {
            string tmp;
            tmp.push_back(carry + '0');
            while (tail_zeroes) {
                tmp.push_back('0');
                tail_zeroes--;
            }
        }
        if (0 == res.size()) {
            return "0";
        }

        return res;
    }

   private:
    string add(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();

        int carry = 0;
        stack<char> stk;
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0 || carry) {
            int x1 = 0, x2 = 0;
            if (i >= 0) {
                x1 = num1[i] - '0';
            }
            if (j >= 0) {
                x2 = num2[j] - '0';
            }
            int x = x1 + x2 + carry;
            if (x >= 10) {
                x -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            stk.push(x + '0');

            i--;
            j--;
        }

        string res;
        while (stk.size() > 0 && '0' == stk.top()) {
            stk.pop();
        }
        while (stk.size() > 0) {
            res.push_back(stk.top());
            stk.pop();
        }
        if (0 == res.size()) {
            return "0";
        }

        return res;
    }
};

int main() {
    Solution sol;
    string num1, num2;

    num1 = "2", num2 = "3";
    cout << sol.multiply(num1, num2) << '\n';

    num1 = "123", num2 = "456";
    cout << sol.multiply(num1, num2) << '\n';

    return 0;
}