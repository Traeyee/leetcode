// Another solution:
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89359/Explanation-of-the-neat-Sort%2BInsert-solution
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Person {
    int h, k, k1;
    Person* next_person;
    Person() = default;
    Person(int hh, int kk) {
        h = hh;
        k = kk;
        k1 = kk;
        next_person = nullptr;
    }
};
typedef Person* PersonPtr;
struct PersonPtrCmp {
    bool operator()(const PersonPtr& p1, const PersonPtr& p2) {
        return p1->h > p2->h ? true : false;
    }
};

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        PersonPtr line_head = nullptr;
        PersonPtr tmp_person_ptr = nullptr;
        for (const auto& person : people) {
            PersonPtr person2 = new Person(person[0], person[1]);
            if (!line_head) {
                line_head = person2;
                tmp_person_ptr = person2;
                continue;
            }
            tmp_person_ptr->next_person = person2;
            tmp_person_ptr = tmp_person_ptr->next_person;
        }
        priority_queue<PersonPtr, vector<PersonPtr>, PersonPtrCmp> people_heap;
        tmp_person_ptr = line_head;
        PersonPtr tmp_person_parent_ptr = nullptr;
        while (tmp_person_ptr) {
            if (0 == tmp_person_ptr->k) {
                people_heap.push(tmp_person_ptr);
                if (tmp_person_ptr == line_head) {
                    line_head = tmp_person_ptr->next_person;
                }
                if (tmp_person_parent_ptr) {
                    tmp_person_parent_ptr->next_person =
                        tmp_person_ptr->next_person;
                }
            } else {
                tmp_person_parent_ptr = tmp_person_ptr;
            }
            tmp_person_ptr = tmp_person_ptr->next_person;
        }
        vector<vector<int>> ret;
        while (ret.size() < people.size()) {
            while (people_heap.size() > 0) {
                const auto person_ptr = people_heap.top();
                people_heap.pop();
                ret.emplace_back(vector<int>{person_ptr->h, person_ptr->k});
                tmp_person_ptr = line_head;
                tmp_person_parent_ptr = nullptr;
                while (tmp_person_ptr) {
                    if (person_ptr->h >= tmp_person_ptr->h) {
                        tmp_person_ptr->k1--;
                    }
                    if (0 == tmp_person_ptr->k1) {
                        people_heap.push(tmp_person_ptr);
                        if (tmp_person_ptr == line_head) {
                            line_head = tmp_person_ptr->next_person;
                        }
                        if (tmp_person_parent_ptr) {
                            tmp_person_parent_ptr->next_person =
                                tmp_person_ptr->next_person;
                        }
                    } else {
                        tmp_person_parent_ptr = tmp_person_ptr;
                    }
                    tmp_person_ptr = tmp_person_ptr->next_person;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> people;
    people.emplace_back(vector<int>{7, 0});
    people.emplace_back(vector<int>{4, 4});
    people.emplace_back(vector<int>{7, 1});
    people.emplace_back(vector<int>{5, 0});
    people.emplace_back(vector<int>{6, 1});
    people.emplace_back(vector<int>{5, 2});
    Solution s;
    auto ret = s.reconstructQueue(people);
    for (const auto& p : ret) {
        cout << p[0] << "," << p[1] << endl;
    }
    return 0;
}