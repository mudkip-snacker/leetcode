#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int x1 = nums[0];
        int frequency = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == x1)
                frequency++;
            else
            {
                if (--frequency == 0)
                {
                    frequency++;
                    i++;
                    x1 = nums[i];
                }
            }
        }

        return x1;
    }
};