/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-04 09:20
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
    string simplifyPath(string path) {
        stack<string> folders;
        string cur_folder;
        for (char c : path) {
            if ('/' == c) {
                if (".." == cur_folder) {
                    if (folders.size() > 0) {
                        folders.pop();
                    }
                } else if ("" != cur_folder && "." != cur_folder) {
                    folders.push(cur_folder);
                }
                cur_folder = "";
            } else {
                cur_folder.push_back(c);
            }
        }
        if (".." == cur_folder) {
            if (folders.size() > 0) {
                folders.pop();
            }
        } else if ("" != cur_folder && "." != cur_folder) {
            folders.push(cur_folder);
        }

        stack<string> tmp_stk;
        while (folders.size() > 0) {
            tmp_stk.push(folders.top());
            folders.pop();
        }
        string res("/");
        while (tmp_stk.size() > 0) {
            res += tmp_stk.top();
            res.push_back('/');
            tmp_stk.pop();
        }
        if (res.size() > 1) {
            res.pop_back();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string path;

    path = "/home/";
    cout << sol.simplifyPath(path) << '\n';

    path = "/../";
    cout << sol.simplifyPath(path) << '\n';

    path = "/home//foo/";
    cout << sol.simplifyPath(path) << '\n';

    return 0;
}