#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int answer = 0;
        for (auto &x : nums)
            answer ^= x;

        return answer;
    }
};