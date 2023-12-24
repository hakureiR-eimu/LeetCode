#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
  private:
    struct DicNode {
        vector<DicNode *> child;
        bool isEnd;
        DicNode() {
            this->child = vector<DicNode *>( 26, nullptr );
            this->isEnd = false;
        }
    };
    DicNode *root;
    bool dfs( string word, int index, DicNode *node ) {
        if ( index == word.length() ) {
            return node->isEnd;
        }
        char ch = word[ index ];
        if ( ch == '.' ) {
            for ( int i = 0; i < 26; ++i ) {
                DicNode *child = node->child[ i ];
                if ( child && dfs( word, index + 1, child ) ) {
                    return true;
                }
            }
        } else if ( ch >= 'a' && ch <= 'z' ) {
            DicNode *child = node->child[ ch - 'a' ];
            if ( child && dfs( word, index + 1, child ) ) {
                return true;
            }
        }
        return false;
    }

  public:
    WordDictionary() { root = new DicNode(); }

    void addWord( string word ) {
        if ( word.length() == 0 ) {
            return;
        }
        DicNode *p = root;
        for ( char item : word ) {
            if ( p->child[ item - 'a' ] != nullptr ) {
                p = p->child[ item - 'a' ];
            } else {
                p->child[ item - 'a' ] = new DicNode();
                p = p->child[ item - 'a' ];
            }
        }
        p->isEnd = true;
    }

    bool search( string word ) { return dfs( word, 0, root ); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
