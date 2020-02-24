// 面试题11. 旋转数组的最小数字

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 二分法
	int minArray(vector<int>& numbers) {
		int len = numbers.size();
		int begin = 0, end = len - 1, mid = 0;

		// 两个while防止{2,2,2,0,2}这样的特例
		while (begin < end)
		{
			if (numbers[begin] == numbers[begin + 1])
				++begin;
			else break;
		}
		while (end > begin)
		{
			if (numbers[end - 1] == numbers[end])
				--end;
			else break;
		}

		if (begin == end) return numbers[0];    // 防止 {2,2,2,2,2} 这样的例子

		while (numbers[begin] >= numbers[end])
		{
			if (end - begin == 1)
			{
				mid = end;
				break;
			}
			mid = (begin + end) / 2;
			if (numbers[mid] >= numbers[begin])
				begin = mid;
			else if (numbers[mid] <= numbers[end])
				end = mid;
		}
		return numbers[mid];
	}

	int minArray1(vector<int>& numbers)
	{
		return *min_element(numbers.data(), numbers.data() + numbers.size());
	}

};

int main() 
{
	vector<int> a = {2,2,2,2,2};
	cout << Solution().minArray(a) << endl;

	std::cout << endl;
	return 0;
}
