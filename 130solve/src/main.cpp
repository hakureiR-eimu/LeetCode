#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static void dfs(vector<vector<char>> &board, int r, int c)
    {
        int rn = board.size();
        int cn = board[0].size();
        if (r < 0 || r >= rn || c < 0 || c >= cn || board[r][c] != 'O')
            return;
        board[r][c] = 'A';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
    static void solve(vector<vector<char>> &board)
    {
        int rn = board.size();
        int cn = board[0].size();
        for (int i = 0; i < cn; ++i)
        {
            dfs(board, 0, i);
            dfs(board, rn - 1, i);
        }
        for (int i = 0; i < rn; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, cn - 1);
        }
        for (int i = 0; i < rn; ++i)
        { // row
            for (int j = 0; j < cn; ++j)
            { // colum
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

int main(int argc, char **argv)
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    Solution::solve(board);
    int rn = board.size();
    int cn = board[0].size();
    for (int i = 0; i < rn; ++i)
    { // row
        for (int j = 0; j < cn; ++j)
        { // colum
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    // cout << "hello world!" << endl;
    return 0;
}
