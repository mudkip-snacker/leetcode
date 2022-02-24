#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int total = 0;
        int sum = 0;
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            m[sum].push_back(i);
        }
        for (const auto &[key, val] : m)
        {
            auto it = m.find(key - k);
            if (it != m.end())
            {
                for (const auto &x : val)
                {
                    for (const auto &y : it->second)
                    {
                        if (y < x)
                            total++;
                        else
                            break;
                    }
                }
            }
        }
        return total;
    }
};

/* Test Cases
[1,1,1]
2
[1,2,3]
3
[2,1,2]
3
[1,2,-1,1,1,-1,1]
3
[1,-1,1,-1,1,-1]
0
*/