#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        if (startGene.empty() || endGene.empty() || bank.empty())
        {
            return -1;
        }
        if (find(bank.begin(), bank.end(), endGene) == bank.end())
        {
            return -1;
        }
        vector<int> visit(bank.size(), 0);
        int step = 0;
        queue<string> q;
        q.push(startGene);
        while (!q.empty())
        {
            step++;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                string temp = q.front();
                q.pop();
                for (int j = 0; j < bank.size(); ++j)
                {
                    if (visit[j] == 0)
                    {
                        int diff = 0;
                        for (int k = 0; k < temp.size(); ++k)
                        {
                            if (temp[k] != bank[j][k]) diff++;
                        }
                        if (diff == 1)
                        {
                            if (bank[j] == endGene) return step;
                            visit[j] = 1;
                            q.push(bank[j]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
