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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *curr = head;
        if (curr == nullptr || curr->next == nullptr) // list has 0 or 1 element
            return curr;

        ListNode *temp;
        ListNode *prev;
        temp = curr;             // 1
        curr = curr->next;       // 2
        temp->next = curr->next; // 3
        curr->next = temp;       // 1
        head = curr;             // 2
        prev = curr->next;       // 1
        curr = curr->next->next; // 3

        while (curr != nullptr)
        {
            temp = curr; // 5
            if (curr->next == nullptr)
                return head;
            curr = curr->next;       // null
            prev->next = curr;       // null
            temp->next = curr->next; // null
            curr->next = temp;       // 3
            prev = curr->next;       // null
            curr = curr->next->next; // null
        }

        return head;
    }
};