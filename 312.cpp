#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        vector<int> bestBalloons;
        int total = 0;
        while (!nums.empty())
        {
            // int next = (1 == nums.size()) ? 1 : nums[1];
            // // Trim small numbers in beginning
            // if (nums.size() > 3 && nums[0] < next && *min_element(begin(nums), end(nums)) == nums[0] && *max_element(begin(nums), end(nums)) == nums[1])
            // {
            //     cout << "num: " << nums[0] << endl;
            //     total += nums[0] * next;
            //     nums.erase(nums.begin());
            //     continue;
            // }
            // // Trim small numbers at the end
            // if (nums.size() > 3 && nums[nums.size() - 1] < nums[nums.size() - 2] && *min_element(begin(nums), end(nums)) == nums[nums.size() - 1] && *max_element(begin(nums), end(nums)) == nums[nums.size() - 2])
            // {
            //     cout << "num: " << nums[nums.size() - 1] << endl;
            //     total += nums[nums.size() - 1] * nums[nums.size() - 2];
            //     nums.erase(nums.begin() + nums.size() - 1);
            //     continue;
            // }

            int maxPopValue = 0;
            int popValue;
            for (int i = 0; i < nums.size(); i++)
            {
                int prevNum = (i == 0) ? 1 : nums[i - 1];
                int nextNum = (i + 1 == nums.size()) ? 1 : nums[i + 1];

                popValue = prevNum * nextNum;
                // popValue = prevNum * nextNum * nums[i];

                // if ((nums[i] < prevNum && nums[i] > nextNum) || (nums[i] > prevNum && nums[i] < nextNum) && nums.size() != 1)
                //     continue;

                cout << "pop value: " << popValue << endl;
                if (popValue > maxPopValue)
                {
                    maxPopValue = popValue;
                    bestBalloons.clear();
                    bestBalloons.push_back(i);
                }
                else if (popValue == maxPopValue)
                    bestBalloons.push_back(i);
            }
            int lowestNumPos = bestBalloons[0];
            int lowestNum = nums[lowestNumPos];
            for (int i = 1; i < bestBalloons.size(); i++)
            {
                if (nums[bestBalloons[i]] < lowestNum)
                {
                    lowestNumPos = bestBalloons[i];
                    lowestNum = nums[lowestNumPos];
                }
            }

            // add coins to total then pop balloon
            cout << "num: " << lowestNum << endl;
            cout << "Max Pop Value: " << maxPopValue << endl;
            maxPopValue *= lowestNum;
            total += maxPopValue;
            nums.erase(nums.begin() + lowestNumPos);
            bestBalloons.clear();
        }

        return total;
    }
};

int main()
{
    vector<int> nums =
        {3, 1, 5, 8};
    Solution sol;
    cout << sol.maxCoins(nums);

    return 0;
}