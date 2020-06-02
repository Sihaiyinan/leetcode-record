// 49. 字母异位词分组

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<char> v;
        map<vector<char>, vector<string>> m;

        for (auto str : strs)
        {
            v.clear();
            for (auto c : str)
            {
                v.push_back(c);
            }
            sort(v.begin(), v.end());
            m[v].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(m.size());
        for (auto & it : m)
            res.push_back(it.second);
        return res;
    }
};

int main()
{

    return 0;
}