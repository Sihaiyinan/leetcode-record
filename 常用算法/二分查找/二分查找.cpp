// 二分查找

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 方法1
int search1(vector<int> nums, int left, int right, int target)
{
	// 在[left，right]里查找target
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
		{
			// 下一轮搜索区间 [left, mid - 1]
			right = mid - 1;
		}
		else
		{
			// 此时，nums[mid] < target, 下一轮搜索区间 [mid + 1, right]
			left = mid + 1;
		}
	}
	return -1;
}

// 方法2, 升序数组
int search2(vector<int> nums, int left, int right, int target)
{
	// 在[left，right]里查找target
	while (left < right)
	{
		// 选择中位数时向下取整
		int mid = left + (right - left) / 2;

		if (nums[mid] < target)
		{
			// 下一轮搜索空间是[mid + 1, right]
			left = mid + 1;
		}
		else
		{
			// 下一轮搜索空间是[left, mid]
			right = mid;
		}
	}
	// 退出循环后，区间只剩下一个元素，视情况， 判断left或者right下标是否符合题意
	return left;
}

// 方法3， 降序数组
int search3(vector<int> nums, int left, int right, int target)
{
	// 在[left，right]里查找target
	while (left < right)
	{
		// 选择中位数时向上取整
		int mid = left + (right - left + 1) / 2;

		if (nums[mid] < target)
		{
			// 下一轮搜索空间是[left, mid - 1]
			right = mid - 1;
		}
		else
		{
			// 下一轮搜索空间是[mid, right]
			left = mid;
		}
	}
	// 退出循环后，区间只剩下一个元素，视情况， 判断left或者right下标是否符合题意
	return left;
}

// 方法4， STL
/*
#include <algorithm>

算法要求序列已经是有序的

lower_bound(beg, end, val)
lower_bound(beg, end, val, comp)
返回一个迭代器，表示第一个小于等于val的元素，如果不存在这样的元素，则返回end。

upper_bound(beg, end, val)
upper_bound(beg, end, val, comp)
返回一个迭代器，表示第一个大于val的元素，如果不存在这样的元素，则返回end。

equal_range(beg, end, val)
equal_range(beg, end, val, comp)
返回一个pair，其first成员是lower_bound返回的迭代器，second成员是upper_bound返回的迭代器。

binary_search(beg, end, val)
binary_search(beg, end, val, comp)
返回一个bool值，指出序列中是否包含等于val的元素。


*/

int main()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	int target = 8;
	
	int res1 = search1(nums, 0, nums.size() - 1, target);
	int res2 = search2(nums, 0, nums.size() - 1, target);
	int res3 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

	cout << "res1 = " << res1 << endl;
	cout << "res2 = " << res2 << endl;
	cout << "res3 = " << res3 << endl;

	return 0;
}
