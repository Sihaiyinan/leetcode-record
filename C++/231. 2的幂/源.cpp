#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && (n & n - 1) == 0;
	}
};

int main() {
	int n = 256;
	cout << Solution().isPowerOfTwo(n);

	cout << endl;
	return 0;
}
