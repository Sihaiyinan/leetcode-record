#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tb = board;
        vector<vector<int>> move = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int num = 0;
                for (auto &m : move)
                {
                    int ni = i + m[0];
                    int nj = j + m[1];
                    if (ni >= 0 && ni < row && nj >= 0 && nj < col)
                    {
                        if (board[ni][nj] == 1)
                            ++num;
                    }
                }
                if (num < 2 || num > 3) tb[i][j] = 0;
                if (num == 3) tb[i][j] = 1;
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                board[i][j] = tb[i][j];
            }
        }
    }
};

int main() {

	cout << endl;
	return 0;
}
