#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
private:
    bool isNum(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '(' || ch == ')' || ch == ' ')
            return false;
        return true;
    }
    int calNum(string num)
    {
        int n = num.length();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum *= 10;
            sum += num[i] - '0';
        }
        return sum;
    }

public:
    int calculate(string s)
    {
        stack<int> stk;
        char ch;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isNum(s[i]))
            {
                string sNum = "";
                while (isNum(s[i]) && i < s.size())
                {
                    sNum.push_back(ch);
                    ++i;
                }
                int num = calNum(sNum);
                stk.push(num);
            }
            else
            {
                switch (s[i])
                {
                case ('+'):
                    int y = stk.top();
                    stk.pop();
                    int x = stk.top();
                    stk.pop();
                    stk.push(x + y);
                    break;
                case ('-'):
                    int y = stk.top();
                    stk.pop();
                    int x = stk.top();
                    stk.pop();
                    stk.push(x - y);
                case ('('):
                case (')'):
                case (' '):
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
