#include <iostream>
#include <map>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Put all list node values into one sorted map
        map<int, int> m;
        for (auto &list : lists)
        {
            ListNode *curr = list;
            while (curr != nullptr)
            {
                m[curr->val]++;
                curr = curr->next;
            }
        }

        // Make map into linked list
        if (m.empty())
            return nullptr;

        // take care of first element in map
        ListNode *head = new ListNode(m.begin()->first);
        ListNode *curr = head;
        for (int i = 1; i < m.begin()->second; i++)
        {
            ListNode *ln = new ListNode(m.begin()->first);
            curr->next = ln;
            curr = curr->next;
        }

        for (auto it = ++m.begin(); it != m.end(); it++)
        {
            for (int i = 0; i < it->second; i++)
            {
                ListNode *ln = new ListNode(it->first);
                curr->next = ln;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main()
{
    return 0;
}