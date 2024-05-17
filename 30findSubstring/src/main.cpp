#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
class Solution {
  public:
    std::vector<int> findSubstring( std::string s,
                                    std::vector<std::string> &words ) {
        std::unordered_map<std::string, int> wordsMap;
        int sLen = s.size();
        int wordLen = words[ 0 ].size();
        for ( int i = 0; i < words.size(); ++i ) {
            wordsMap[ words[ i ] ] = i;
        }
        for ( int i = 0; i < s.size(); ++i ) {
            if ( i + wordLen >= sLen ) {
                break;
            }
        }
    }
};
int main( int argc, char **argv ) { return 0; }
