#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        if (matrix.empty()) return res;
        int u = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; ++i) res.push_back(matrix[u][i]);
            u++;
            if (u > b) break;
            for (int i = u; i <= b; ++i) res.push_back(matrix[i][r]);
            r--;
            if (l > r) break;
            for (int i = r; i >= l; --i)
            {
                res.push_back(matrix[b][i]);
            }
            b--;
            if (u > b) break;
            for (int i = b; i >= u; --i)
            {
                res.push_back(matrix[i][l]);
            }
            l++;
            if (l > r) break;
        }
        return res;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
