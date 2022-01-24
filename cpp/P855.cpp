/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-02 21:58
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

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

// 有错
class ExamRoom {
   public:
    ExamRoom(int n) : n_(0), max_n_(n), head_(nullptr) {}

    int seat() {
        if (n_ == max_n_) {
            return -1;
        }
        if (0 == n_) {
            head_ = new Node(0);
            n_++;
            return 0;
        } else if (1 == n_) {  // TODO: 有错
            head_->next = new Node(max_n_ - 1);
            n_++;
            return max_n_ - 1;
        }

        Node *ptr = head_, *max_l_ptr;
        int max_l = 0;
        for (int i = 0; i < n_ - 1; i++) {
            int l = ptr->next->val - ptr->val;
            if (l > max_l && !(l == max_l + 1 && l % 2 == 1)) {
                max_l = l;
                max_l_ptr = ptr;
            }
            ptr = ptr->next;
        }
        ptr = max_l_ptr;
        int mid = (ptr->next->val - ptr->val) / 2 + ptr->val;
        Node* new_node = new Node(mid);
        new_node->next = ptr->next;
        ptr->next = new_node;
        n_++;
        return mid;
    }

    void leave(int p) {
        Node *prev = nullptr, *ptr = head_;
        while (ptr) {
            if (ptr->val == p) {
                if (prev) {
                    prev->next = ptr->next;
                } else {
                    head_ = head_->next;
                }
                delete ptr;
                n_--;
                return;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }

    void print() {
        auto ptr = head_;
        while (ptr) {
            cout << ptr->val << ", ";
            ptr = ptr->next;
        }
        cout << '\n';
    }

   private:
    int n_, max_n_;
    Node* head_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {
    ExamRoom examRoom(10);
    // cout << examRoom.seat() << '\n';  // return 0, no one is in the room,
    // then
    //                                   // the student sits at seat number 0.
    // cout << examRoom.seat()
    //      << '\n';  // return 9, the student sits at the last seat number 9.
    // cout << examRoom.seat()
    //      << '\n';  // return 4, the student sits at the last seat number 4.
    // cout << examRoom.seat()
    //      << '\n';  // return 2, the student sits at the last seat number 2.
    // examRoom.leave(4);
    // cout << examRoom.seat()
    //      << '\n';  // return 5, the student sits at the last seat number 5.

    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    examRoom.leave(0);
    examRoom.leave(4);
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    cout << examRoom.seat() << '\n';
    examRoom.leave(0);

    return 0;
}