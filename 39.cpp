#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> helper(vector<int> &candidates, int target, int start)
    {
        vector<vector<int>> answer;

        for (int i = start; i < candidates.size(); ++i)
        {
            int x = candidates[i];
            if (x > target)
                return answer;
            if (x == target)
                answer.push_back({x});
            for (auto y : helper(candidates, target - x, i))
            {
                y.push_back(x);
                answer.push_back(y);
            }
        }

        return answer;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        return helper(candidates, target, 0);
    }
};

/* test cases
[1,3,6,7,10]
20
[1,2,3]
4
*/