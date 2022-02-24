#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0;
        unordered_map<char, int> m;
        queue<char> q;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (m.count(c)) // repeated letter
            {
                if (q.size() > longest)
                    longest = q.size();

                // remove elements of queue and set up to and including repeated letter
                int pop = m[c] - i + q.size() + 1;
                while (pop--)
                {
                    char key = q.front();
                    q.pop();
                    m.erase(key);
                }
            }
            m[c] = i;
            q.push(c);
        }

        return (longest > q.size()) ? longest : q.size();
    }
};