#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string answer = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2)
                return num.substr(0, i + 1);
        }
        return answer;
    }
};

int main()
{
    return 0;
}