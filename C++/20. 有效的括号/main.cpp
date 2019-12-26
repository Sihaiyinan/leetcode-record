#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        vector<char> stack;
        for (auto &c : s)
        {
            if (stack.empty() && (c == ')' || c == '}' || c == ']'))
                return false;
            if (c == '(' || c == '{' || c == '[')
                stack.push_back(c);
            else if (!(c + stack.back() == '(' + ')' || c + stack.back() == '{' + '}' || c + stack.back() == '[' + ']'))
                return false;
            else
                stack.pop_back();
        }
        return stack.empty();
    }
};

int main()
{
    string s = "()[]{}";
    cout << Solution().isValid(s) << endl;
    return 0;
}