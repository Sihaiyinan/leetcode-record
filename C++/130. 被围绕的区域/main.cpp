// 130. 被围绕的区域

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        int row = board.size();
        int col = board[0].size();

        vector<int> keep(row * col);
        vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                // 在边界上
                if ((i == 0 ||i == row - 1 || j == 0 || j == col - 1) && board[i][j] == 'O')
                {
                    keep[i * col + j] = 1;
                    board[i][j] = 'X';

                    queue<vector<int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto tmp = q.front();
                        q.pop();

                        for (auto m : move)
                        {
                            int nx = tmp[0] + m[0];
                            int ny = tmp[1] + m[1];

                            if (nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == 'O')
                            {
                                q.push({nx, ny});
                                board[nx][ny] = 'X';
                                keep[nx * col + ny] = 1;
                            }
                        }

                    }
                }
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (keep[i * col + j] == 1)
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }


    }
};

int main()
{

    return 0;
}

