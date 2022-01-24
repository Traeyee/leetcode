/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 10:18
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

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_set<string> visited = {beginWord};
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);

        while (q.size() > 0) {
            string w = q.front().first;
            int depth = q.front().second;

            for (int i = 0; i < w.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string w2 =
                        w.substr(0, i) + c + w.substr(i + 1, w.size() - i - 1);
                    if (word_set.end() != word_set.find(w2) &&
                        visited.end() == visited.find(w2)) {
                        if (w2 == endWord) {
                            return depth + 1;
                        }
                        visited.insert(w2);
                        q.emplace(w2, depth + 1);
                    }
                }
            }

            q.pop();
        }

        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord, endWord;
    vector<string> wordList;

    beginWord = "hit", endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << "\n";

    wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << "\n";

    return 0;
}