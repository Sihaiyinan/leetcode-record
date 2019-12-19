#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len < 1) return s;

		vector<int> p(len);
		vector<int> p1(len);
		vector<int> p2(len);
		int max_len = 0;
		string re = s.substr(0, 1);

		for (int j = 0; j < len; ++j)
		{
			for (int i = 0; i < j; ++i)
			{
				if ((p1[i + 1] or (j - i <= 2)) && s[i] == s[j])
				{
					p2[i] = 1;
					if (j - i + 1 > max_len)
					{
						max_len = j - i + 1;
						re = s.substr(i, max_len);
					}
				}
			}
			p1 = p2;
			p2 = p;
		}
		return re;
	}
};

int main()
{
	Solution S;
	string s = "babad";
	string re = S.longestPalindrome(s);
	
	for (auto& i : re) cout << i << ' ';
	cout << endl;

	return 0;
}