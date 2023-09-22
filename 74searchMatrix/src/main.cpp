#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),c = matrix[0].size();
        for(int i =0;i<r;++i){
            if(matrix[i][c-1]<target) continue;
            if(matrix[i][0] >target) return false;
            for(int j = 0;j<c;++j){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
