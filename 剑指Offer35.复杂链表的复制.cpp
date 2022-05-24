class Solution {
public:
    //  hashmap
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr)
            return head;

        unordered_map<Node*,Node*> extraMap;

        Node* temp = head;
        while(temp)
        {
            extraMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp)
        {
            extraMap[temp]->next = extraMap[temp->next];
            extraMap[temp]->random = extraMap[temp->random];
            temp = temp->next;
        }

        return extraMap[head];
    }
};