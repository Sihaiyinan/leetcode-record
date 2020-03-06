// 面试题50. 第一个只出现一次的字符

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i)
        {
            m[s[i]] += 1;
        }
        char re = ' ';
        for (auto &i : s)
        {
            if (m[i] == 1)
            {
                re = i;
                break;
            }
        }
        return re;
    }
};

int main() {
    string s = "leetcode";
    cout << Solution().firstUniqChar(s) << endl;


    std::cout << std::endl;
    return 0;
}
