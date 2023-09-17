#include <iostream>
#include <vector>
using namespace std;

class Trie
{
private:
    vector<Trie*> children;
    bool          isEnd;

public:
    Trie(): children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie* node = this;
        int   i    = 0;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
            ++i;
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie* node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return false;
            }
            node = node->children[ch];
        }
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return false;
            }
            node = node->children[ch];
        }
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(int argc, char** argv)
{
    string word   = "hotdog";
    string prefix = "dog";
    Trie*  root   = new Trie();
    root->insert(word);
    bool output = root->startsWith(prefix);
    cout << output << endl;
    return 0;
}
