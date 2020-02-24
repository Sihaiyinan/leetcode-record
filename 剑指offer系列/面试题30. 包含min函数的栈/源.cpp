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
		if (m_stack.empty() || x < m_stack[m_stack.size() - 1])
			m_stack.push_back(x);
		else
			m_stack.push_back(m_stack[m_stack.size() - 1]);
		stack.push_back(x);
	}

	void pop() {
		stack.pop_back();
		m_stack.pop_back();
	}

	int top() {
		return stack[stack.size() - 1];
	}

	int min() {
		return m_stack[m_stack.size() - 1];
	}
	
private:
	vector<int> stack;
	vector<int> m_stack;
};

int main() 
{



	std::cout << endl;
	return 0;
}
