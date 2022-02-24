#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int findMax1(vector<int> &nums)
    {
        int sum = 0;
        int best = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            int possibleBest = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j] ? 1 : -1;
                if (sum == 0)
                    possibleBest = j + 1 - i;
            }
            best = max(best, possibleBest);
        }

        return best;
    }

    int findMax2(vector<int> &nums)
    {
        int sum = 0, sum2 = 0;
        int best = 0, best2 = 0;
        int firstNum = nums[0];
        int start = 0;
        bool skip = true;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == firstNum && skip)
            {
                continue;
            }
            else if (skip)
            {
                skip = false;
                sum += firstNum ? 1 : -1;
                start = i;
            }
            sum += nums[i] ? 1 : -1;
            sum2 += nums[i] ? 1 : -1;
            // cout << "Sum2: " << sum2 << endl;
            if (sum == 0)
                best = i + 1 - start;
            if (sum2 == 0)
                best2 = i + 1 - start;
        }

        return max(best, best2);
    }

    int findMax3(vector<int> &nums)
    {
        int sum = 0;
        int best = 0;
        int counter = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] ? 1 : -1;
            if (sum == 0)
                best = i + 1;
        }

        return best;
    }

    int findMax4(vector<int> &nums)
    {
        map<int, pair<int, int>> track;
        track[0] = make_pair(-1, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] ? 1 : -1;
            if (track.find(sum) != track.end())
            {
                cout << "change " << sum << " " << track[sum].first << " " << track[sum].second << endl;
                track[sum].second += i - track[sum].first;
                track[sum].first = i;
                cout << "to " << sum << " " << track[sum].first << " " << track[sum].second << endl;
            }
            else
            {
                cout << "new " << sum << " " << i << " " << 0 << endl;
                track[sum] = make_pair(i, 0);
            }
        }
        int max = 0;
        for (auto i = track.begin(); i != track.end(); i++)
        {
            if (i->second.second > max)
                max = i->second.second;
        }
        return max;
    }

    int findMaxLength(vector<int> &nums)
    {
        return findMax1(nums);
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0};
    // vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1};
    Solution sol;
    int ans = sol.findMax4(nums);

    cout << "Answer: " << ans << endl;
    return 0;
}