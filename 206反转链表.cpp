// 206 反转链表

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL)
        {
            return NULL;
        }
            

        struct ListNode* pnew = (struct ListNode*)new(struct ListNode);
        pnew->next= NULL;
        
        struct ListNode*p = head;
        while(p)
        {
            struct ListNode* s = (struct ListNode*)new(struct ListNode);
            s->val = p->val;
            s->next = pnew->next;
            pnew->next=s;
            p = p->next;
        }

        return pnew->next;
    }
};