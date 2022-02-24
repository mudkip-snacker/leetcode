#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        list<string> s;
        for (auto &word : wordList)
            s.push_back(word);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty())
        {
            const string currentWord = q.front().first;
            const int level = q.front().second;
            q.pop();

            for (auto it = s.begin(); it != s.end();)
            {
                int differences = 0;
                for (int i = 0; i < currentWord.size(); i++)
                {
                    if (currentWord[i] != (*it)[i])
                        differences++;
                }
                if (differences == 1)
                {
                    if (*it == endWord)
                        return level + 1;
                    q.push({*it, level + 1});
                    it = s.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }

        return 0;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution sol;
    cout << sol.ladderLength("hit", "cog", wordList);
}
/* Test Cases
"hit"
"cog"
["bit", "bot", "bog", "cog"]
"hit"
"tot"
["tot"]
*/