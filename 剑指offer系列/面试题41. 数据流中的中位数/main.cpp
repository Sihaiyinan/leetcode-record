// 面试题41. 数据流中的中位数

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		lo.push(num);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size())
		{
			lo.push(hi.top());
			hi.pop();
		}
	}

	double findMedian() {
		return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
	}


private:
	priority_queue<int> lo;  // 大顶堆
	priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆
};


int main()
{
	cout << MedianFinder().findMedian() << endl;


	std::cout << std::endl;
	return 0;
}