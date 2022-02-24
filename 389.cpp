#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    char badSolution(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            size_t c = t.find(s[i]);
            if (c != string::npos)
                t.erase(t.find(s[i]), 1);
            else
                return s[i];
        }

        return t[0];
    }

    char badSolution2(string s, string t)
    {
        unordered_map<char, int> ms, mt;
        for (int i = 0; i < s.size(); i++)
            ms[s[i]]++;

        for (int i = 0; i < t.size(); i++)
            mt[t[i]]++;

        for (auto const &x : mt)
        {
            if (x.second != ms[x.first])
                return x.first;
        }

        return '\0';
    }

    char findTheDifference(string s, string t)
    {
        char c = 0;
        for (char &x : s)
            c ^= x;
        for (char &x : t)
            c ^= x;

        return c;
    }
};

int main()
{
    Solution sol;
    cout << sol.findTheDifference("abcd", "aebcd");
    return 0;
}