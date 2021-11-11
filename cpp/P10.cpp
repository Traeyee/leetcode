/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-10 11:45
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

struct State {
    // -1: fail
    // 0: init
    // 1: literal
    // 2: any
    // 3: wildcard
    int val;
    char c;
};

struct RegexPart {
    int l, r;
    bool is_wildcard;
    char c;
    RegexPart(int l, int r) : l(l), r(r), is_wildcard(false) {}
    RegexPart(int l, int r, bool is_wildcard, char c)
        : l(l), r(r), is_wildcard(is_wildcard), c(c) {}
};

class Solution {
   public:
    bool isMatch(string s, string p) {
        // 分为若干个literal
        int s_len = s.size(), p_len = p.size(), p_ptr = 0;
        vector<RegexPart> regex_parts;
        int l = 0, r = -1;
        while (p_ptr < p_len) {
            if (p_ptr + 1 < p_len && '*' == p[p_ptr + 1]) {
                if (l <= r && r < p_ptr) {
                    regex_parts.emplace_back(l, r);
                }
                regex_parts.emplace_back(p_ptr, p_ptr + 1, true, p[p_ptr]);
                p_ptr += 2;
                l = p_ptr;
                r = l - 1;
                continue;
            }

            p_ptr++;
            r++;
        }
        if (r < p_len) {
            regex_parts.emplace_back(l, r);
        }

        vector<vector<int>> end_pos_list(regex_parts.size() + 1, vector<int>());
        end_pos_list[0].emplace_back(-1);
        for (int l = 1; l <= regex_parts.size(); l++) {
            auto& regex_part = regex_parts[l - 1];
            for (const auto& end_pos : end_pos_list[l - 1]) {
                // cout << "# l=" << l << ": " << end_pos << "\n";
                int i = end_pos + 1;
                if (regex_part.is_wildcard) {
                    end_pos_list[l].emplace_back(i - 1);
                    while (i < s_len) {
                        if ('.' != regex_part.c && s[i] != regex_part.c) {
                            break;
                        }
                        end_pos_list[l].emplace_back(i);
                        i++;
                    }
                } else {
                    bool match = true;
                    int k = regex_part.l;
                    while (k <= regex_part.r) {
                        if (i >= s_len || ('.' != p[k] && s[i] != p[k])) {
                            match = false;
                            // cout << "# s_len=" << s_len << "\n";
                            // cout << s[i] << "--" << p[k] << "\n";
                            // cout << "# here [" << regex_part.l << ", " << regex_part.r << "]" << i << "--" << k << "\n";
                            break;
                        }
                        k++;
                        i++;
                    }
                    if (match) {
                        end_pos_list[l].emplace_back(i - 1);
                    }
                }
            }
        }

        auto& last_end_pos = end_pos_list[end_pos_list.size() - 1];
        for (const auto& pos : last_end_pos) {
            if (s.size() - 1 == pos) {
                return true;
            }
        }

        // for (int i = 0; i < regex_parts.size(); i++) {
        //     auto regex_part = regex_parts[i];
        //     cout << "# wildcard=" << regex_part.is_wildcard << "[" << regex_part.l << ", "
        //          << regex_part.r << "]";
        //     for (auto tmp2 : end_pos_list[i + 1]) {
        //         cout << tmp2 << ", ";
        //     }
        //     cout << "\n";
        // }

        return false;
    }

    // 自动机法
    bool isMatch0(string s, string p) {
        int p_len = p.size(), p_ptr = 0;
        State state;
        for (const auto& c : s) {
            // read pattern
            if (0 == state.val) {
                if (p_ptr >= p_len) {
                    return false;
                }
                char c1 = p[p_ptr];
                state.c = c1;
                if ('.' == c1) {
                    state.val = 2;
                } else {
                    state.val = 1;
                }
                if (p_ptr + 1 < p_len && '*' == p[p_ptr + 1]) {
                    state.val = 3;
                    p_ptr++;
                }
                p_ptr++;
            }

            if (1 == state.val) {
                if (c == state.c) {
                    state.val = 0;
                } else {
                    return false;
                }
            } else if (2 == state.val) {
                state.val = 0;
            } else if (3 == state.val) {
                // if ()
            }
        }

        return p_ptr == p_len;
    }
};

int main() {
    Solution sol;
    string s, p;

    s = "aa", p = "a";
    cout << sol.isMatch(s, p) << "\n";

    s = "aa", p = "a*";
    cout << sol.isMatch(s, p) << "\n";

    s = "ab", p = ".*";
    cout << sol.isMatch(s, p) << "\n";

    s = "aab", p = "c*a*b";
    cout << sol.isMatch(s, p) << "\n";

    s = "mississippi", p = "mis*is*p*.";
    cout << sol.isMatch(s, p) << "\n";

    s = "mississippi", p = "mis*is*ip*.";
    cout << sol.isMatch(s, p) << "\n";

    return 0;
}