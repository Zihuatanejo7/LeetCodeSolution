class Solution
{
public:
    // 234.  回文链表
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow, * fast;
        fast = slow = head;

        while (fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow 到链表中点

        fast = head;
        slow = slow->next;

        stack<ListNode*>st;
        while (slow)
        {
            st.push(slow);
            slow = slow->next;
        }

        while (!st.empty())
        {
            if (fast->val != st.top()->val)
            {
                return false;
            }

            st.pop();
            fast = fast->next;
        }
        return true;
    }
};