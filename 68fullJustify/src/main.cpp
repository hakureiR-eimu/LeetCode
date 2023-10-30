#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> fullJustify( vector<string> &words, int maxWidth ) {
        vector<string> res;
        int            row = 0, left = 0, right = 0;
        while ( right < words.size() ) {
            int sumWidth = 0;
            while ( right < words.size() &&
                    sumWidth + words[ right ].length() + right - left <=
                        maxWidth ) {
                sumWidth += words[ right ].length();
                right++;
            }
            int leftWidth = maxWidth - sumWidth;
            int num       = right - left;

            string s = words[ left ];

            if ( right == words.size() ) {
                for ( int i = left + 1; i < right; ++i ) {
                    s += " " + words[ i ];
                }
                for ( int i = s.length(); i < maxWidth; ++i ) {
                    s += " ";
                }
            } else if ( right - left == 1 ) {
                for ( int i = s.length(); i < maxWidth; ++i ) {
                    s += " ";
                }
            } else {
                int blankWidth = leftWidth / ( num - 1 );
                int extraWidth = leftWidth % ( num - 1 );
                if ( extraWidth == 0 ) {
                    for ( int i = left + 1; i < right; ++i ) {
                        for ( int j = 0; j < blankWidth; j++ ) {
                            s += " ";
                        }
                        s += words[ i ];
                    }
                } else {
                    for ( int i = left + 1; i < right; ++i ) {

                        if ( extraWidth != 0 ) {
                            for ( int j = 0; j < blankWidth + 1; j++ ) {
                                s += " ";
                            }
                            s += words[ i ];
                            extraWidth--;
                        } else {
                            for ( int j = 0; j < blankWidth; j++ ) {
                                s += " ";
                            }
                            s += words[ i ];
                        }
                    }
                }
            }
            res.push_back( s );
            // cout << s << endl;
            left = right;
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    // cout << "hello world!" << endl;
    vector<string> words    = { "a" };
    int            maxWidth = 1;
    Solution      *p        = new Solution();
    p->fullJustify( words, maxWidth );
    return 0;
}
