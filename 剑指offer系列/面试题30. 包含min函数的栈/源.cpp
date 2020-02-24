// 面试题30. 包含min函数的栈
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (x < min_value)
			min_value = x;
		stack.push_back(x);
	}

	void pop() {
		if (stack[stack.size() - 1] == min_value)
			min_value = *min_element(stack.data(), stack.data() + stack.size() - 1);
		stack.pop_back();
	}

	int top() {
		return stack[stack.size() - 1];
	}

	int min() {
		return min_value;
	}
	
private:
	int min_value = 0x7FFFFFFF;
	vector<int> stack;
};

int main() 
{



	std::cout << endl;
	return 0;
}
