#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        this->edges.resize(numCourses);
        this->visited.resize(numCourses);
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        return valid;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
