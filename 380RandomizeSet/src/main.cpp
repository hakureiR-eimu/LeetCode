#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> indexM;
    vector<int>             nums;

public:
    RandomizedSet()
    {
        srand((unsigned) time(nullptr));
    }

    bool insert(int val)
    {
        if (indexM.count(val)) return false;
        int index = nums.size();
        nums.emplace_back(val);
        indexM[val] = index;
        return true;
    }

    bool remove(int val)
    {
        if (! indexM.count(val)) return false;
        int index    = indexM[val];
        int last     = nums.back();
        nums[index]  = last;
        indexM[last] = index;
        nums.pop_back();
        indexM.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
