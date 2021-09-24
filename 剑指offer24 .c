// 剑指offer 24.反转链表

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;

    // 头插法 （带头结点）
    struct ListNode* pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
    pnew->next = NULL;

    struct ListNode* p = head;
    while (p)
    {
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));

        s->val = p->val;
        s->next = pnew->next;
        pnew->next= s;

        p = p->next;
    }

    return pnew->next;
}