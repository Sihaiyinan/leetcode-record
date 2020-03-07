// 面试题59 - II. 队列的最大值

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if (maxq.empty()) return -1;
        return maxq.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!maxq.empty() && value > maxq.back())
            maxq.pop_back();
        maxq.push_back(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int m = q.front();
        q.pop();
        if (m == maxq.front())
            maxq.pop_front();
        return m;
    }

private:
    queue<int> q;
    deque<int> maxq;  // 双端队列
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */


int main() {


    std::cout << std::endl;
    return 0;
}
