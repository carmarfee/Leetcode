#include <malloc.h>

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
    ListNode *factorial(ListNode *l1, ListNode *l2, int over)
    {
        if (!(l1 == NULL && l2 == NULL))
        {
            if (l1 == NULL && l2 != NULL)
            {
                ListNode *p = new ListNode();
                p->val = (0 + l2->val + over) % 10;
                over = (0 + l2->val + over) / 10;
                p->next = factorial(l1, l2->next, over);
                return p;
            }
            else if (l1 != NULL && l2 == NULL)
            {
                ListNode *p = new ListNode();
                p->val = (0 + l1->val + over) % 10;
                over = (0 + l1->val + over) / 10;
                p->next = factorial(l1->next, l2, over);
                return p;
            }
            else
            {
                ListNode *p = new ListNode();
                p->val = (l2->val + l1->val + over) % 10;
                over = (l2->val + l1->val + over) / 10;
                p->next = factorial(l1->next, l2->next, over);
                return p;
            }
        }
        if (over)
        {
            ListNode *p = new ListNode();
            p->val = 1;
            p->next = NULL;
            return p;
        }
        return NULL;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int over = 0;
        ListNode *ans = factorial(l1, l2, over);
        return ans;
    }
};


//
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
