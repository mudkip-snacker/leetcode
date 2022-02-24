#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == k)
            return "0";

        string answer = "";
        answer += num[0];
        for (int i = 1; i < num.size(); i++)
        {
            if (k > 0 && num[i] - '0' < answer.back() - '0')
            {
                k--;
                answer.pop_back();
                i--;
            }
            else
                answer += num[i];
        }

        while (k > 0) // digits are in non-descending order which means you erase from the back
        {
            answer.pop_back();
            k--;
        }

        // Remove leading zeroes
        size_t pos = answer.find_first_not_of('0');
        if (pos != string::npos)
        {
            answer.erase(0, pos);
            return answer;
        }
        else // number is all zeroes
            return "0";
    }
};

int main()
{
    string hi = "hi";
    hi.erase(0, 0);
    cout << hi << endl;
    return 0;
}

/* Plan
1. If you can remove all numbers in front of a 0 or group of 0's, do it. (it's like removing a free digit)
*/

/* Test Cases
"0"
1
"12224"
3
"45700390401"
5
*/