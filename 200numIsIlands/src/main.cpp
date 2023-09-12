#include <iostream>
#include <vector>

using namespace std;
class Solution
{
private:
    int dfs(vector<vector<char>> &grid, int rI, int cI)
    {
        if (!isValid(grid, rI, cI))
        {
            return 0;
        }
        else if (grid[rI][cI] == '2' || grid[rI][cI] == '0')
        {
            return 0;
        }
        else
        {
            grid[rI][cI] = '2';
            dfs(grid, rI, cI + 1);
            dfs(grid, rI, cI - 1);
            dfs(grid, rI - 1, cI);
            dfs(grid, rI + 1, cI);
            return 1;
        }
    }
    bool isValid(vector<vector<char>> &grid, int rI, int cI)
    {
        int r = grid.size(), c = grid[0].size();
        return rI >= 0 && rI < r && cI >= 0 && cI < c;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cnt += dfs(grid, i, j);
            }
        }
        return cnt;
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
