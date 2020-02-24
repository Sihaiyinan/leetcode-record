// 面试题09. 用两个栈实现队列

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		if (stack2.size() <= 0)
		{
			while (stack1.size() > 0)
			{
				int &data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		if (stack2.empty()) return -1;
		int &head = stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main() 
{


	std::cout << endl;
	return 0;
}
