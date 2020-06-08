// 605. 种花问题

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, c = 0;
        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                ++c;
            }
            ++i;
        }
        return c >= n;
    }
};

int main()
{
    return 0;
}