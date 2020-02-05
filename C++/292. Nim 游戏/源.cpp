#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return (n % 4) != 0;
	}
};

int main() {
	int n = 256;
	cout << Solution().canWinNim(n);

	cout << endl;
	return 0;
}
