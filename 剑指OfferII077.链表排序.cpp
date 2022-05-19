class Solution 
{
public:
    ListNode* sortList(ListNode* head)
    {
        // single element or null 
        if (nullptr == head || head->next == nullptr)
            return head;

        multiset<int> myset;

        ListNode* help = head;
        while (help)
        {
            myset.insert(help->val);
            help = help->next;
        }

        ListNode* pnew = new ListNode(-1);
        ListNode* last = pnew;
        pnew->next = nullptr;

        multiset<int>::iterator it = myset.begin();
        while (it != myset.end())
        {
            ListNode* temp = new ListNode(*it);
            last->next = temp;
            last = temp;
            it++;
        }
        last->next = nullptr;
        return pnew->next;
    }
};