#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m; // map from value in nums to index in nums
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (const auto &[key, val] : m)
        {
            // cout << "Key: " << key << " Val: " << val << endl;
            int key2 = target - key;
            if (m.find(key2) != m.end())
            {
                if (key != key2)
                {
                    answer.push_back(m[key2]);
                    answer.push_back(val);
                    return answer;
                }
                else
                { // account for if the answer is same value e.g. 3+3
                    auto it = find(nums.begin(), nums.end(), key);
                    int pos = it - nums.begin();
                    auto it2 = find(nums.begin() + pos + 1, nums.end(), key);
                    if (it2 != nums.end())
                    {
                        answer.push_back(pos);
                        answer.push_back(it2 - nums.begin());
                        return answer;
                    }
                }
            }
        }

        throw(invalid_argument(__PRETTY_FUNCTION__));
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 8, 11, 15};

    try
    {
        vector<int> ans = sol.twoSum(v, 9);
        cout << ans[0] << " " << ans[1] << endl;
    }
    catch (std::invalid_argument &ia)
    {
        cout << "Invalid argument: " << ia.what();
        return 1;
    }

    return 0;
}