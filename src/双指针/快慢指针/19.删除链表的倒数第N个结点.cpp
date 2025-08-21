
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr; // 如果链表为空或只有一个节点，直接返回空
        }
        // 快指针先走 n 步
        while (n-- > 0 && fast != nullptr)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            if (fast->next == nullptr)
            {
                // 当快指针到达链表末尾时，慢指针即为要删除节点的前一个节点
                ListNode *toDelete = slow->next; // 要删除的节点
                slow->next = toDelete->next;     // 跳过要删除的节点
                delete toDelete;                 // 释放内存
                return head;                     // 返回头节点
            }
            slow = slow->next; // 慢指针每次走一步
            fast = fast->next; // 快指针每次走一步
        }
        return head->next;
    }
};