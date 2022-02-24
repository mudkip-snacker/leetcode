#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> getCounts(vector<int> &nums)
    {
        unordered_map<int, int> ret;
        for (auto &n : nums)
        {
            if (ret.find(n) != ret.end())
                ++ret.at(n);
            else
                ret[n] = 1;
        }
        return ret;
    }
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int tuples = 0;
        int n = nums1.size();
        auto nn1 = getCounts(nums1);
        auto nn2 = getCounts(nums2);
        auto nn3 = getCounts(nums3);
        auto nn4 = getCounts(nums4);
        unordered_map<int, int> nn12;
        // cout << "d1\n";
        for (auto &n1 : nn1)
        {
            for (auto &n2 : nn2)
            {
                int sum = n1.first + n2.first;
                if (nn12.find(sum) != nn12.end())
                    nn12.at(sum) += n1.second * n2.second;
                else
                    nn12[sum] = n1.second * n2.second;
            }
        }
        // cout << "d2\n";
        unordered_map<int, int> nn34;
        for (auto &n3 : nn3)
        {
            for (auto &n4 : nn4)
            {
                int sum = n3.first + n4.first;
                if (nn34.find(sum) != nn34.end())
                    nn34.at(sum) += n3.second * n4.second;
                else
                    nn34[sum] = n3.second * n4.second;
            }
        }
        // cout << "d3\n";

        for (auto &n12 : nn12)
        {
            if (nn34.find(-n12.first) != nn34.end())
                tuples += n12.second * nn34.at(-n12.first);
        }
        // for (auto &n1 : nn1)
        // {
        //     for (auto &n2 : nn2)
        //     {
        //         for (auto &n3 : nn3)
        //         {
        //             int sum = -(n1.first + n2.first + n3.first);
        //             if (nn4.find(sum) != nn4.end())
        //                 tuples += n1.second * n2.second * n3.second * nn4.at(sum);
        //             // for (int l = 0; l < n; l++)
        //             // {
        //             //     if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
        //             //         tuples++;
        //             // }
        //         }
        //     }
        // }
        return tuples;
    }
};
// num1 * num2
// 1 2
// 3 4
// 5 6
// 7 8
// 1+3:1 1+4:1 2+3:1 2+4:1, 5+7 5+8 6+7 6+8

// n^2*3 12n
// n^4 16n

// 300
// 10000

// for (13 14 23 24) O(1)
// 1 2
// 3 4
// 5 6
// 7 8
// 1357 1358 1367 1368 1457 1458 1467 1468 2357 2358 2367 2368 2457 2458 2467 2468

int main()
{
    vector<int> n1 = {1, 2};
    vector<int> n2 = {-2, -1};
    vector<int> n3 = {-1, 2};
    vector<int> n4 = {0, 2};

    Solution sol;
    int ans = sol.fourSumCount(n1, n2, n3, n4);
    cout << "Answer: " << ans << endl;
    return 0;
}