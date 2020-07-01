// 71. 简化路径

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
#include <sstream>


using namespace std;

class Solution {
public:
    vector<string> split(const string &str, char c)
    {
        vector<string> res;
        string re;
        istringstream reStream(str);

        while (getline(reStream, re, c))
        {
            if (re.empty() || re == "." || (re == ".." && res.empty()))
                continue;
            else if (re == ".." && !res.empty())
                res.pop_back();
            else
                res.push_back(re);
        }
        return res;
    }

    string simplifyPath(string path) {
        string res;
        auto lists = split(path, '/');
        for (auto s : lists)
        {
            res += "/";
            res += s;
        }
        return res.empty() ? "/" : res;
    }
};

int main()
{
    string s = "/a/../../b/../c//.//";
    cout << Solution().simplifyPath(s) << endl;

    return 0;
}