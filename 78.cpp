#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> answer;
        answer.push_back({});

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = answer[i].empty() ? 0 : m[answer[i].back()] + 1; j < nums.size(); j++)
            {
                vector<int> v(answer[i]);
                v.push_back(nums[j]);
                answer.push_back(v);
                if (v == nums)
                    return answer;
            }
        }

        return answer;
    }
};