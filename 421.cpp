#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <bitset>
using namespace std;

// A class to store a Trie node
class Trie
{
public:
    bool isLeaf;
    Trie *bit[2];

    // Constructor
    Trie()
    {
        this->isLeaf = false;

        for (int i = 0; i < 2; i++)
        {
            this->bit[i] = nullptr;
        }
    }

    void insert(int num)
    {
        std::string str = bitset<32>(num).to_string();
        Trie *curr = this;
        for (int i = 0; i < str.length(); i++)
        {
            // create a new node if the path doesn't exist
            if (curr->bit[str[i] - '0'] == nullptr)
            {
                curr->bit[str[i] - '0'] = new Trie();
            }

            // go to the next node
            curr = curr->bit[str[i] - '0'];
        }

        // mark the current node as a leaf
        curr->isLeaf = true;
    }
    // bool search(int num)
    // {
    //     std::string str = bitset<8>(num).to_string();
    //     // return false if Trie is empty
    //     if (this == nullptr)
    //         return false;

    //     Trie *curr = this;
    //     for (int i = 0; i < str.length(); i++)
    //     {
    //         // go to the next node
    //         curr = curr->bit[str[i]];

    //         // if the string is invalid (reached end of a path in the Trie)
    //         if (curr == nullptr)
    //         {
    //             return false;
    //         }
    //     }

    //     // return true if the current node is a leaf and the
    //     // end of the string is reached
    //     return curr->isLeaf;
    // }
    // bool haveChildren(Trie const *curr)
    // {
    //     for (int i = 0; i < 2; i++)
    //     {
    //         if (curr->bit[i])
    //         {
    //             return true; // child found
    //         }
    //     }

    //     return false;
    // }
};

int setBitNumber(int n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    if (n == INT32_MAX)
        return -1 >> 1;
    n = n + 1;
    return (n >> 1);
}

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        // Convert vector to trie
        set<int> ss;
        for (auto &n : nums)
        {
            ss.insert(n);
        }

        Trie *head = new Trie();
        int max = 0;
        int msb = 0;
        for (auto &s : ss)
        {
            head->insert(s);
            if (s > max)
            {
                max = s;
                msb = setBitNumber(s);
            }
        }
        vector<int> out;
        for (auto &s : ss)
        {
            if (s & msb)
                out.push_back(s);
        }

        max = 0;

        for (auto &s : out)
        {
            std::string s1 = bitset<32>(s).to_string();
            std::string s2;
            // cout << "test high bit num " << s1 << endl;
            Trie *num = head;
            for (auto &c1 : s1)
            {
                if (c1 == '0' && num->bit[1] != nullptr)
                {
                    s2 += "1";
                    num = num->bit[1];
                }
                else if (c1 == '0' && num->bit[0] != nullptr)
                {
                    s2 += "0";
                    num = num->bit[0];
                }
                else if (c1 == '1' && num->bit[0] != nullptr)
                {
                    s2 += "0";
                    num = num->bit[0];
                }
                else if (c1 == '1' && num->bit[1] != nullptr)
                {
                    s2 += "1";
                    num = num->bit[1];
                }
                else
                {
                    cout << "ouch\n";
                    exit(1);
                }
            }

            // // Find maxXOR
            // Trie *num1 = head;
            // Trie *num2 = head;
            // // string n1 = "";
            // string n2 = "";
            // while (num1)
            // {
            //     if (num1->bit[1])
            //     {
            //         n1 += "1";
            //         if (num2->bit[0])
            //         {
            //             num2 = num2->bit[0];
            //             n2 += "0";
            //         }
            //         else
            //         {
            //             num2 = num2->bit[1];
            //             n2 += "1";
            //         }
            //         num1 = num1->bit[1];
            //     }
            //     else
            //     {
            //         n1 += "0";
            //         if (num2->bit[1])
            //         {
            //             num2 = num2->bit[1];
            //             n2 += "1";
            //         }
            //         else
            //         {
            //             num2 = num2->bit[0];
            //             n2 += "0";
            //         }
            //         num1 = num1->bit[0];
            //     }
            // }
            int nn1 = stoi(s1, nullptr, 2);
            int nn2 = stoi(s2, nullptr, 2);

            // cout << "highest complement " << s2 << endl;
            // cout << "xor is " << (nn1 ^ nn2) << endl;
            if ((nn1 ^ nn2) > max)
                max = nn1 ^ nn2;
        }
        return max;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {14, 70};
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << sol.findMaximumXOR(nums) << endl;

    return 0;
}