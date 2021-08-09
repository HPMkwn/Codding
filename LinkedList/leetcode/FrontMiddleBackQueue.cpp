#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
   public:
    deque<int> q1, q2;
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        q1.push_front(val);
        if ((q1.size() - 1) > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }

    void pushMiddle(int val) {
        if (q1.size() > q2.size()) {
            int temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
        }
        q1.push_back(val);
    }

    void pushBack(int val) {
        q2.push_back(val);
        if (q2.size() > q1.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }

    int popFront() {
        int ret = -1;
        if (q1.size() > 0) {
            ret = q1.front();
            q1.pop_front();
            if (q1.size() < q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        }
        return ret;
    }

    int popMiddle() {
        int ret = -1;
        if (q1.size() > 0) {
            ret = q1.back();
            q1.pop_back();
            if (q1.size() < q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        }
        return ret;
    }
    int popBack() {
        int ret = -1;
        if (q2.size()) {
            ret = q2.back();
            q2.pop_back();
            if (q1.size() - 1 > q2.size()) {
                q2.push_front(q1.back());
                q1.pop_back();
            }
        } else if (q1.size()) {
            ret = q1.back();
            q1.pop_back();
        }
        return ret;
    }
};