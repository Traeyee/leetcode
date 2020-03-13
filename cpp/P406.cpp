#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

struct Person {
    int h, k, k1;
    Person() = default;
    Person(int hh, int kk) {
        h = hh;
        k = kk;
        k1 = kk;
    }
    // bool operator <(const Person& p) {
    //     return k < p.k || (k == p.k && h << p.h) ? true : false;
    // }
    // bool operator ==(const Person& p) {
    //     return k > p.k || (k == p.k && h > p.h) ? true : false;
    // }
};

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // auto cmp = [](Person& p1, Person& p2) {
        //     if (p1.k > p2.k) {
        //         return true;
        //     } else if (p1.k == p2.k) {
        //         return p1.h > p2.h ? true : false;
        //     }
        //     return false;
        // };
        priority_queue<Person, vector<Person>, greater<Person>> people_heap;
        for (const auto& person : people) {
            people_heap.push(Person(person[0], person[1]));
        
        
        vector<vector<int>> ret;
        return ret;
    }
};

int main() {
    priority_queue<int, vector<int>, less<int>> max_heap;
    for (int i = 0; i < 10; i++) {
        max_heap.push(i);
    }
    while (max_heap.size() > 0) {
        int ele = max_heap.top();
        max_heap.pop();
        cout << ele << endl;
    }

    return 0;
}