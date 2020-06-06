// 128. 最长连续序列

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int w = 0, h = 0;
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> visited;

    bool dfs(vector<vector<char>>& board, int x, int y, string &word, int p)
    {
        if (p == word.size()) return true;
        for (auto m : move)
        {
            int ni = x + m[0];
            int nj = y + m[1];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni * w + nj] && board[ni][nj] == word[p])
            {
                visited[ni * w + nj] = 1;
                if (dfs(board, ni, nj, word, p + 1)) return true;
                visited[ni * w + nj] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;

        h = board.size();
        w = board[0].size();

        visited.assign(w * h, 0);

        for (int i = 0; i < h; ++i)
        {
            int cur = 0;
            for (int j = 0; j < w; ++j)
            {
                if (board[i][j] == word[cur])
                {
                    visited[i * w + j] = 1;
                    if (dfs(board, i, j, word, cur + 1))
                        return true;
                    visited[i * w + j] = 0;
                }
            }
        }
        return false;
    }
};



int main()
{

    return 0;
}