// 1095. 山脉数组中查找目标值

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MountainArray {
public:
	int get(int index);
	int length();
};



class Solution {
	// 二分查找
	int binary_search(MountainArray &mountain, int left, int right, int target, int key(int))
	{
		target = key(target);

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int cur = key(mountain.get(mid));

			if (cur == target)
				return mid;
			else if (cur < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int left = 0;
		int right = mountainArr.length() - 1;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (mountainArr.get(mid) < mountainArr.get(mid + 1))
				left = mid + 1;
			else
				right = mid;
		}

		int peak = left;

		int index = binary_search(mountainArr, 0, peak, target, [](int x) -> int {return x; });
		if (index != -1)
			return index;
		return binary_search(mountainArr, peak + 1, mountainArr.length() - 1, target, [](int x) -> int {return x; });
	}
};


int main()
{

	return 0;
}
