// 面试题 02.02. 返回倒数第 k 个节点

int kthToLast(struct ListNode* head, int k)
    {
        if (k < 1 || head ==NULL)
            return -1;
        
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        
        int i = 0;
        while (i < k)
        {
            fast = fast->next;
            i++;
        }
        
 
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
     
        return slow->val;
    }