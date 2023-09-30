#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
private:
    bool isValidNine(vector<char>& tmp)
    {
        int hash[10] = {0};
        for (int i = 0; i < 9; ++i)
        {
            char num = tmp[i];
            if (num == '.')
            {
            }
            else
            {
                if (hash[num - '0'] > 0)
                {
                    // cout << i << endl;
                    return false;
                }
                hash[num - '0']++;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<char> tmp;
        for (int i = 0; i < 9; ++i)
        { // row
            tmp.clear();
            for (int j = 0; j < 9; ++j)
            {
                tmp.push_back(board[i][j]);
            }
            if (!isValidNine(tmp))
            {
                cout << "row r:" << i << endl;
                return false;
            }
        }

        // tmp.clear();
        for (int i = 0; i < 9; ++i)
        {
            tmp.clear();
            for (int j = 0; j < 9; ++j)
            {
                tmp.push_back(board[j][i]);
            }
            if (!isValidNine(tmp))
            {
                cout << "column c:" << i << endl;
                return false;
            }
        }

        // tmp.clear();
        for (int i = 0; i < 3; ++i)
        {
            int rStart = 3 * i;
            for (int j = 0; j < 3; ++j)
            {
                int cStart = 3 * j;
                tmp.clear();
                for (int row = rStart; row < rStart + 3; ++row)
                {
                    // cout << row << endl;
                    for (int column = cStart; column < cStart + 3; ++column)
                    {
                        // cout << column << endl;
                        tmp.push_back(board[row][column]);
                    }
                }
                if (!isValidNine(tmp))
                {
                    // cout << "nine r:" << i << " c:" << j << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, char** argv)
{
    std::vector<std::vector<char>> sudokuBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution* sol = new Solution();
    bool res = sol->isValidSudoku(sudokuBoard);
    cout << res << endl;
    return 0;
}
