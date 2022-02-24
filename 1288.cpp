#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end()); // sort ascending by first value of each vector

        int result = 1;
        int x1 = intervals[0][0];
        int y1 = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            int x2 = intervals[i][0];
            int y2 = intervals[i][1];

            if (y2 > y1)
            {
                y1 = y2;
                if (x2 > x1)
                {
                    x1 = x2;
                    result++;
                }
            }
        }

        return result;
    }
};