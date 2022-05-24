class Solution
{
public:
    //86. 分隔链表
    ListNode* partition(ListNode* head, int x)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* largeHead, * smallHead, * largeLast, * smallLast, * temp;


        largeHead = new ListNode(-1);
        largeLast = largeHead;

        smallHead = new ListNode(-1);
        smallLast = smallHead;

        temp = head;
        while (temp)
        {
            if (temp->val < x)
            {
                smallLast->next = temp;
                smallLast = temp;
            }
            else
            {
                largeLast->next = temp;
                largeLast = temp;
            }

            temp = temp->next;
        }

        if (smallHead->next == nullptr)
        {
            largeLast->next = nullptr;
            return largeHead->next;
        }

        if (largeHead->next == nullptr)
        {
            smallLast->next == nullptr;
            return smallHead->next;
        }

        smallLast->next = largeHead->next;
        largeLast->next = nullptr;
        return smallHead->next;

    }
};