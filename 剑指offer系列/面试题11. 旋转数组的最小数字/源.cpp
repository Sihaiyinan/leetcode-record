// 面试题11. 旋转数组的最小数字

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int len = numbers.size();
		int begin = 0, end = len - 1;


		int mid = (end + begin + 1) / 2;

		while ((end - begin) > 1)
		{
			if (numbers[begin] <= numbers[mid])
			{
				if (numbers[mid] <= numbers[end])
					return numbers[begin];

				begin = mid;
				mid = (end - begin) / 2 + begin;
			}
			else
			{
				if (numbers[mid] > numbers[end])
					return numbers[end];

				end = mid;
				mid = (end - begin) / 2 + begin;
			}
		}
		return numbers[end];
	}

	int minArray1(vector<int>& numbers)
	{
		return *min_element(numbers.data(), numbers.data() + numbers.size());
	}

};

int main() 
{
	vector<int> a = {1,3 };
	cout << Solution().minArray(a) << endl;

	std::cout << endl;
	return 0;
}
