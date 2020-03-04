// 面试题40. 最小的k个数

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int compare(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty()) return arr;

        vector<int> re;
        qsort(arr.data(), arr.size(), sizeof(arr[0]), compare);
        for (int i = 0; i < k; ++i)
        {
            re.push_back(arr[i]);
        }
        return re;
    }
};


int main() {
    vector<int> a = {2,4,3,5,6,1}, b;
    b = Solution().getLeastNumbers(a, 2);



    std::cout << std::endl;
    return 0;
}
