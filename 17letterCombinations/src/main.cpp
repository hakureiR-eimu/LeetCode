#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<string> res;
    string tmp;
    vector<string> board = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int pos)
    {
        if (pos == digits.size())
        {
            res.push_back(tmp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < board[num].size(); ++i)
        {
            tmp.push_back(board[num][i]);
            dfs(digits, pos + 1);
            tmp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0) return res;
        res.clear();
        dfs(digits, 0);
        return res;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
