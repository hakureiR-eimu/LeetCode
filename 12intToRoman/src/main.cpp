#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        const pair<int, string> valSymbols[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string roman;
        for (const auto& [value, symbol] : valSymbols)
        {
            while (num >= value)
            {
                num -= value;
                roman += symbol;
            }
            if (num == 0)
            {
                break;
            }
        }
        return roman;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
