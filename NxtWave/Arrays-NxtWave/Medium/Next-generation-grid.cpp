

/*


Approach

1)check editorial there is a beutiful explanation
2)we use state encoding


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int countneigh(vector<vector<int>> &board, int r, int c, int m, int n)
    {
        int neighbours = 0;
        for (int i = r - 1; i <= r + 1; i++)
        {
            for (int j = c - 1; j <= c + 1; j++)
            {
                if ((i == r && j == c) || i < 0 || j < 0 || i >= m || j >= n)
                    continue;

                if (board[i][j] == 1 || board[i][j] == 3)
                    neighbours++;
            }
        }
        return neighbours;
    }

    void nextGenerationGrid(vector<vector<int>> &board)
    {
        // Write your code here...
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int neighbours = countneigh(board, i, j, m, n);

                if (board[i][j] == 1)
                {
                    if (neighbours == 2 || neighbours == 3)
                    {
                        board[i][j] = 3;
                    }
                }
                else
                {
                    if (neighbours == 3)
                    {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2 || board[i][j] == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};
