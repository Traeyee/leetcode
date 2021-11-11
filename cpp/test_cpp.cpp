/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-01 15:58
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

void test_unordered_map(vector<int>& nums) {
    unordered_map<string, int> map;
    int last_bucket_count = -1;
    cout << map.bucket_count() << "\n";
    for (size_t i = 0; i < nums.size(); i++) {
        stringstream ss;
        ss << nums[i];
        map[ss.str()] = i;
        if (last_bucket_count != map.bucket_count()) {
            cout << "(" << i << ")[" << ss.str() << "]:" << last_bucket_count
                 << "-->" << map.bucket_count()
                 << ", d=" << map.bucket_count() - last_bucket_count << "\n";
            last_bucket_count = map.bucket_count();
        }
    }
}

void test_unordered_map() {
    vector<int> nums;
    for (size_t i = 0; i < 10000; i++) {
        nums.emplace_back(i);
    }
    test_unordered_map(nums);

    auto rng = std::default_random_engine{};
    shuffle(nums.begin(), nums.end(), rng);
    test_unordered_map(nums);
}

void test_bit_op() {
    // -1: 11...11
    int a, b;
    a = 0;
    b = ~a;  // -1
    cout << b << "\n";

    a = 1;  // 00...01
    b = ~a;  // 11...10
    cout << b << "\n";  // -2
    // 说明c++取反都是取反真实补码（包括符号位）

    // 左移最特殊，不能对负数操作，正数可能变负数
    a = 1 << 31;  // 1(32)00...0
    cout << a << "\n";  // -2147483648，即负0
    // warning: shifting a negative signed value is undefined
    b = ~a;
    cout << b << "\n";  // 2147483647

    a = 2;
    b = a >> 1;
    cout << b << "\n";
    a = -2;
    b = a >> 1;
    cout << b << "\n";
    // 说明右移不改变符号位
}

void test_reserve() {
    vector<int> v;
    v.reserve(10);
    v.push_back(8);
    cout << v[0] << ", " << v[10] << "\n";

    vector<int> w;
    w.reserve(10);
    w.push_back(9);
    cout << w[0] << ", " << w[10] << "\n";

    vector<int> x;
    x.resize(10);
    x.push_back(10);
    cout << x[0] << ", " << x[10] << "\n";

    vector<int> y;
    y.resize(10);
    y.push_back(11);
    cout << y[0] << ", " << y[10] << "\n";
}

int main() {
    test_reserve();

    return 0;
}