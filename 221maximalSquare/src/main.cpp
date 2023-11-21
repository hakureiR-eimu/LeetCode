#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int maximalSquare( vector<vector<char>> &matrix ) {
        if(matrix.size()==0||matrix[0].size()==0){
            return 0;
        }
        int maxSize =0;
        int rowLen = matrix.size();
        int volLen = matrix[0].size();
        int dp[1005][1005]={0};
        for(int i=0;i<rowLen;++i){
            for(int j =0;j<volLen;++j){
                if(matrix[i][j]=='1'){
                    if(i==0||j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    }
                }
                maxSize = max(maxSize,dp[i][j]);
            }
        }
        int maxSquare = maxSize * maxSize;
        return maxSquare;
    }
};

int main( int argc, char **argv ) {
    vector<vector<char>> matrix = { { '1', '0', '1', '0', '0' },
                                    { '1', '0', '1', '1', '1' },
                                    { '1', '1', '1', '1', '1' },
                                    { '1', '0', '0', '1', '0' } };
    cout << "hello world!" << endl;
    return 0;
}
