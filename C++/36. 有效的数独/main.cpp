// 36. 有效的数独

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty()) return false;

        vector<int> m(10);
        for (int i = 0; i < 9; ++i)
        {
            m.assign(10, 0);
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.') continue;
                m[board[i][j] - '0']++;
                if (m[board[i][j] - '0'] > 1) return false;
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            m.assign(10, 0);
            for (int j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.') continue;
                m[board[j][i] - '0']++;
                if (m[board[j][i] - '0'] > 1) return false;
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                m.assign(10, 0);
                for (int ii = i; ii < i + 3; ++ii)
                {
                    for (int jj = j; jj < j + 3; ++jj)
                    {
                        if (board[ii][jj] == '.') continue;
                        m[board[ii][jj] - '0']++;
                        if (m[board[ii][jj] - '0'] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> b = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout << Solution().isValidSudoku(b) << endl;
    return 0;
}