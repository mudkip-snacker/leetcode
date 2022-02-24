#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            // Convert nums vector into a map (key: num, value: occurrences of num)
            unordered_map<int, int> m;
            for (auto &x : nums)
                m[x]++;

            return count_if(begin(m), end(m),
                            [](const pair<const int, int> &p)
                            {
                                return p.second > 1;
                            });
        }
        else
        {
            int numPairs = 0;

            // Convert nums vector into a set
            set<int> s;
            for (auto &x : nums)
                s.insert(x);
            for (const auto &x : s)
            {
                if (s.count(x + k))
                    numPairs++;
            }

            return numPairs;
        }
    }
};

int main()
{
    return 0;
}