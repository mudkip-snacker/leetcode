#include <iostream>

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;

        ListNode *ln = new ListNode();
        if (sum >= 10)
        {
            ln->val = sum % 10;
            if (l1)
            {
                if (l1->next)
                    l1->next->val++;
                else
                    l1->next = new ListNode(1);
            }
            else
            {
                if (l2->next)
                    l2->next->val++;
                else
                    l2->next = new ListNode(1);
            }
        }
        else
            ln->val = sum;

        if ((l1 && l1->next) || (l2 && l2->next))
        {
            if (!l1 || !l1->next)
                ln->next = addTwoNumbers(nullptr, l2->next);
            else if (!l2 || !l2->next)
                ln->next = addTwoNumbers(l1->next, nullptr);
            else
                ln->next = addTwoNumbers(l1->next, l2->next);
        }

        return ln; // no more next numbers
    }
};