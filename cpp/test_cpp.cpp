/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-01 15:58
 * @brief
 */
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
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

    a = 1;              // 00...01
    b = ~a;             // 11...10
    cout << b << "\n";  // -2
    // 说明c++取反都是取反真实补码（包括符号位）

    // 左移最特殊，不能对负数操作，正数可能变负数
    a = 1 << 31;        // 1(32)00...0
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

void test_real_random() {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> dist(0, 1);

    unordered_map<double, int> counter;
    for (int i = 0; i < 10000; i++) {
        double p = dist(mt);
        if (p < 0.2) {
            counter[0.2]++;
        } else if (p < 0.4) {
            counter[0.4]++;
        } else if (p < 0.6) {
            counter[0.6]++;
        } else if (p < 0.8) {
            counter[0.8]++;
        } else if (p <= 1) {
            counter[1]++;
        } else {
            counter[100]++;
        }
    }

    for (const auto& p : counter) {
        cout << p.first << ": " << p.second << "\n";
    }
    cout << "\n";
}

// https://zhuanlan.zhihu.com/p/97128024
int lvar = 123;
int& get_lref() { return lvar; }
int get_lval() { return lvar; }
void test_lvalue() {
    const int& a = get_lref();
    int& b = get_lref();
    cout << lvar << "\n";
    cout << get_lref() << "\n";
    cout << a << "\n";
    cout << b << "\n";

    const int& a1 = get_lval();
    //     error: non-const lvalue reference to type 'int' cannot bind
    //       to a temporary of type 'int'
    //     int& b1 = get_lval();
    //          ^    ~~~~~~~~~~
    // 1 error generated.
    // 因为左值引用并不是左值，并没有建立一片稳定的内存空间，所以如果不是const的话你就可以对它的内容进行修改，而右值又不能进行赋值，所以就会出错。因此只能用const的左值引用来绑定一个右值
    // int& b1 = get_lval();
    cout << lvar << "\n";
    cout << get_lval() << "\n";
    cout << a1 << "\n";
    // cout << b1 << "\n";
}

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << "\n";
}

void test_iterator() {
    vector<int> a = {1, 2, 3}, b;
    b.insert(b.end(), a.begin() + 10, a.end());
    print_vector(b);
}

void _test_static1() {
    static int x = 1;
    x++;
    cout << x << '\n';
}

void _test_static2() {
    static int x = 10;
    x++;
    cout << x << '\n';
}

void test_static() {
    _test_static1();
    _test_static2();
    _test_static1();
    _test_static2();
}

void test_unique_ptr() { unique_ptr<int> p1(new int(1)); }

class Cls1 {
   public:
    virtual void foo1() {
        a = 2;
        cout << a << '\n';
    }
    // virtual void foo2()=0;

   private:
    typedef int T1;
    int a;
};

class Cls2 {
   public:
    typedef int T2;
};

class SubCls1 : Cls1 {
   public:
    int foo1(int a1) {
        cout << "b\n";
        return 0;
    }
};

void test_virtual() { SubCls1 sc1; }

struct RValue {
    RValue() : name_("undefined") { cout << name_ << ": default\n"; }
    RValue(string name) : name_(name) {}
    RValue(RValue& rv) { cout << name_ << ": copy\n"; }
    RValue(RValue&& rv) { cout << name_ << ": move\n"; }
    RValue& operator=(RValue& rv) {
        cout << name_ << ": =\n";
        if (this != &rv) {
            name_ = rv.name_;
        }
        return *this;
    }
    RValue& operator=(RValue&& rv) {
        cout << name_ << ": =r\n";
        if (this != &rv) {
            name_ = rv.name_;
        }
        return *this;
    }
    string name_;
};

struct PRValue {
    RValue rv;
};

void _test_rvalue(PRValue& prv) {
    auto tmp1 = new RValue;
    unique_ptr<RValue> p1(tmp1);
    unique_ptr<RValue> p2(tmp1);

    RValue rv2("2");
    // prv.rv = rv2;
    // prv.rv = move(rv2);
    prv.rv = RValue(move(rv2));
}
void test_rvalue() {
    // int& a;

    PRValue prv;
    _test_rvalue(prv);
}

void test_fork() {
    int pid;
    pid = fork();
    pid = fork();
    pid = fork();
    printf("%d: hello work\n", pid);
}

void test_tmp() {
    double a = 1 / 3;
    cout << a << '\n';
}

void test_bit() {
    int x1 = 1 << 31;
    cout << x1 << '\n';
    int x2 = ~x1;
    cout << x2 << '\n';
}

void test_map_op() {
    // us
    chrono::system_clock::time_point ts;
    // auto ts0 = chrono::system_clock::now();
    // this_thread::sleep_for(chrono::milliseconds(1500));
    // ts = chrono::system_clock::now();
    // double s = (ts - ts0).count() / 1000000.0;
    // cout << s << '\n';

    // time_t ts;
    // time_t ts0 = time(0);
    // this_thread::sleep_for(chrono::milliseconds(1500));
    // ts = time(0);
    // auto intv = ts - ts0;
    // cout << ts << " - " << ts0 << " = " << intv << '\n';
}

void test_assign_seq() {
    int i = 10, j = i + 1;
    cout << i << ", " << j << '\n';
}

void test_typedef() {
    // Cls1::T1 t1;
    Cls2::T2 t2;
}

int main() {
    test_assign_seq();

    return 0;
}