// 面试题40. 最小的k个数

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int compare(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

class Solution {
public:
    // 方法1，排序
    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        if (arr.empty()) return arr;
        vector<int> re;
        qsort(arr.data(), arr.size(), sizeof(arr[0]), compare);
        for (int i = 0; i < k; ++i)
        {
            re.push_back(arr[i]);
        }
        return re;
    }

    // 方法2，partition函数
    vector<int> getLeastNumbers2(vector<int>& arr, int k) {
        if (arr.empty()) return arr;
        vector<int> re;

        int begin = 0, end = arr.size() - 1;
        int index = partition(arr, begin, end);
        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
                index = partition(arr, begin, end);
            } else{
              begin = index + 1;
              index = partition(arr, begin, end);
            }
        }
        for (int i = 0; i < k; ++i)
            re.push_back(arr[i]);

        return re;
    }

    int partition(vector<int> &arr, int begin, int end)
    {
        int val = arr[begin];
        while (begin < end)
        {
            while (begin < end && arr[end] >= val)
                --end;
            arr[begin] = arr[end];
            while (begin < end && arr[begin] <= val)
                ++begin;
            arr[end] = arr[begin];
        }
        arr[begin] = val;
        return begin;
    }

    // 方法3，set
    vector<int> getLeastNumbers3(vector<int>& arr, int k) {
        if (arr.empty()) return arr;
        multiset<int, greater<int>> m;
        vector<int> re;
        for (auto iter = arr.begin(); iter != arr.end(); ++iter)
        {
            if (m.size() < k)
            {
                m.insert(*iter);
            } else{
                if (*(m.begin()) > *iter)
                {
                    m.erase(m.begin());
                    m.insert(*iter);
                }
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            re.push_back(*it);
        }
        return re;
    }


    };

int main() {
    vector<int> n = {3,2,1}, re;
    int k = 2;

    re = Solution().getLeastNumbers3(n, k);
    std::cout << std::endl;
    return 0;
}
