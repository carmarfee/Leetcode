struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head; // 如果链表为空或只有一个节点，直接返回头节点
        }
        ListNode *slow = head;
        ListNode *fast = head;
        // 确保快指针可以走两步,最终到达nullptr
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // 慢指针每次走一步
            fast = fast->next->next; // 快指针每次走两步
            if (fast == nullptr || fast->next == nullptr)
            {
                return slow; // 当快指针到达链表末尾时，慢指针即为中间节点
            }
        }
        return head;
    }
};