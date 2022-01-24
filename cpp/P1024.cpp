/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-05 20:42
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
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(), clips.end(), [](vector<int>& x1, vector<int>& x2) {
            if (x1[0] < x2[0]) {
                return true;
            } else if (x1[0] == x2[0] && x1[1] > x2[1]) {
                return true;
            }
            return false;
        });

        int last_end = clips[0][1], tmp_rightmost_end = -1,
            leftmost_end = clips[0][0];
        int i = 1, cnt = 1;
        while (i < n && last_end < time) {
            auto& clip = clips[i];

            // cout << "#0:" << clip[0] << "-" << clip[1] << "\n";

            if (last_end < clip[0]) {  // 已经没有重叠或相接的了
                last_end = tmp_rightmost_end;
                // cout << "#1:" << clip[0] << "-" << clip[1] << "\n";
                cnt++;
            }

            if (clip[0] <= last_end) {
                // cout << "#here\n";
                // 找出能接上的最右段
                if (clip[1] > tmp_rightmost_end) {
                    tmp_rightmost_end = clip[1];
                }
                i++;
            } else {
                break;
            }
        }
        if (last_end < time && last_end < tmp_rightmost_end) {
            last_end = tmp_rightmost_end;
            // cout << "#2\n";
            cnt++;
        }

        // cout << "##" << leftmost_end << "-" << last_end << "\n";
        if (leftmost_end > 0 || last_end < time) {
            return -1;
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<vector<int>> clips;
    int time;

    clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
    time = 10;
    cout << s.videoStitching(clips, time) << "\n";

    clips = {{0, 1}, {1, 2}};
    time = 5;
    cout << s.videoStitching(clips, time) << "\n";

    clips = {{0, 1}, {6, 8}, {0, 2}, {5, 6}, {0, 4}, {0, 3}, {6, 7}, {1, 3},
             {4, 7}, {1, 4}, {2, 5}, {2, 6}, {3, 4}, {4, 5}, {5, 7}, {6, 9}};
    time = 9;
    cout << s.videoStitching(clips, time) << "\n";

    clips = {{0, 4}, {2, 8}};
    time = 5;
    cout << s.videoStitching(clips, time) << "\n";

    clips = {{5, 7}, {1, 8}, {0, 0}, {2, 3}, {4, 5}, {0, 6}, {5, 10}, {7, 10}};
    time = 5;
    cout << s.videoStitching(clips, time) << "\n";

    clips = {{3, 12}, {7, 14}, {9, 14}, {12, 15},
             {0, 9},  {4, 14}, {2, 7},  {1, 11}};
    time = 10;
    cout << s.videoStitching(clips, time) << "\n";

    return 0;
}