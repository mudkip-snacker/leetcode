using namespace std;

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
    ListNode *merge(ListNode *left, ListNode *right)
    {
    }

    ListNode *sortList(ListNode *head)
    {
        ListNode *curr = head;
        int size = 0;
        while (curr != nullptr)
        {
            size++;
            curr = curr->next;
        }

        ListNode *sortedList = merge()
    }
};