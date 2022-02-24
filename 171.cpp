#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int columnNum = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--)
            columnNum += (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.size() - i - 1);

        return columnNum;
    }
};