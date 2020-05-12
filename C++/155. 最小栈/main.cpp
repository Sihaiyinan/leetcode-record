// 155. 最小栈

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (stack.empty())
        {
            stack.push_back(x);
            min_val = x;
        }
        else
        {
            stack.push_back(x);
            min_val = min(min_val, x);
        }
    }

    void pop() {
        if (stack.back() <= min_val)
        {
            stack.pop_back();
            if (!stack.empty())
            {
                min_val = *min_element(stack.begin(), stack.end());
            }
        }
        else
            stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_val;
    }
private:
    int min_val = 0;
    vector<int> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main()
{

    return 0;
}