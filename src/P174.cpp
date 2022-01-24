/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 14:25
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

// 若下个dp线路为cur = c1, min = m1, 当d[i] > 0, cur = c1 + d[i]，否则，cur = c1 - d[i]，还得更新min1
// 若两条线路(c1, m1), (c2, m2)
// -9, (1, -1), (3, -5)
// 是否存在使得新的 c1 > c2，m1 < m2