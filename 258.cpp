#include <iostream>

class Solution
{
public:
    int addDigits(int num)
    {
        if (num)
            return (num % 9) ? num % 9 : 9;
        else
            return 0;
    }
};

int main()
{
    return 0;
}