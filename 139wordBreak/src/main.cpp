#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool wordBreak( string s, vector<string> &wordDict ) {
        int lenS = s.length();
        int lenD = wordDict.size();
        unordered_map<string, int> map;
        for ( int i = 0; i < lenD; ++i ) {
            map[ wordDict[ i ] ] = i;
        }
        int dp[ 10005 ] = { 0 };
        dp[ 0 ] = 1;
        for ( int i = 0; i < lenS; ++i ) {
            // cout<<"i:"<<i<<endl;
            if ( dp[ i ] == 1 ) {
                string tmp = "";
                for ( int j = i; j < lenS; ++j ) {
                    // cout<<"j:"<<j<<endl;
                    tmp += s.at( j );
                    if ( map.find( tmp ) != map.end() ) {
                        dp[ j + 1 ] = 1;
                        // cout<<"map:"<<tmp<<"j+1:"<<j+1<<endl;
                    }
                }
            } else {
                continue;
            }
        }
        return dp[ lenS ];
    }
};

int main( int argc, char **argv ) {
    // cout << "hello world!" << endl;
    Solution *p = new Solution;
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    int boolres = p->wordBreak( s, wordDict );
    cout << boolres << endl;
    return 0;
}
