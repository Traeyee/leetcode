/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-19 20:11
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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Line {
    float k, b;
    float x;
    bool vertical;
    Line() : k(0.0), b(0.0), vertical(false), x(0.0) {}
    Line(Point &p1, Point &p2) {
        if (p1.x == p2.x) {
            vertical = true;
            b = p1.x;
            x = p1.x;
        } else {
            vertical = false;
            k = static_cast<float>(p1.y - p2.y) /
                static_cast<float>(p1.x - p2.x);
            b = static_cast<float>(p1.y) - k * static_cast<float>(p1.x);
        }
    }
    string get_hash() {
        stringstream ss;
        if (vertical) {
            ss << "#" << x;
        } else {
            ss << k << "-" << b;
        }
        return ss.str();
    }
    bool is_on(const Point &p) {
        if (vertical) {
            return fabs(x - p.x) < 1e-8;
        } else {
            // cout << "#here1: " << k * p.x + b - p.y << "\n";
            return fabs(k * p.x + b - p.y) < 1e-8;
        }
    }
};

class Solution {
   public:
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size();
        if (1 == n) {
            return 1;
        }

        vector<Point> points2;
        for (int i = 0; i < n; i++) {
            points2.emplace_back(points[i][0], points[i][1]);
        }

        vector<Line> lines;
        unordered_set<string> line_hashes;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto line = Line(points2[i], points2[j]);
                auto line_hash = line.get_hash();
                if (line_hashes.end() == line_hashes.find(line_hash)) {
                    lines.emplace_back(line);
                    line_hashes.insert(line_hash);
                }
            }
        }

        int max_cnt = 0;
        // cout << "# " << lines.size() << "\n";
        for (auto &line : lines) {
            int cnt = 0;
            cout << line.get_hash() << "\n";
            for (auto &p : points2) {
                if (line.is_on(p)) {
                    // cout << "## " << p.x << ", " << p.y << "\n";
                    cnt++;
                }
            }
            max_cnt = cnt > max_cnt ? cnt : max_cnt;
        }

        return max_cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;

    // points = {{1, 1}, {2, 2}, {3, 3}};
    // cout << sol.maxPoints(points) << "\n";

    // points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    // cout << sol.maxPoints(points) << "\n";

    points = {{54, 153},   {1, 3},      {0, -72},    {-3, 3},     {12, -22},
              {-60, -322}, {0, -5},     {-5, 1},     {5, 5},      {36, 78},
              {3, -4},     {5, 0},      {0, 4},      {-30, -197}, {-5, 0},
              {60, 178},   {0, 0},      {30, 53},    {24, 28},    {4, 5},
              {2, -2},     {-18, -147}, {-24, -172}, {-36, -222}, {-42, -247},
              {2, 3},      {-12, -122}, {-54, -297}, {6, -47},    {-5, 3},
              {-48, -272}, {-4, -2},    {3, -2},     {0, 2},      {48, 128},
              {4, 3},      {2, 4}};
    cout << sol.maxPoints(points) << "\n";

    return 0;
}