#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> max_heap;
        int res = 0;
        for (int elem : nums)
        {
            max_heap.push(elem);
        }
        for (int i = 0; i < k; ++i)
        {
            res = max_heap.top();
            max_heap.pop();
        }
        return res;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
