/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head==nullptr) return head;
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = newnode->next;
        }
        temp = head;
        Node *dummy = temp->next;
        // place randoms
        while (temp != nullptr)
        {
            if (temp->random == nullptr) dummy->random = nullptr;
            else   dummy->random = temp->random->next;

            if (temp->next)
                temp = temp->next->next;
            if (dummy->next)
                dummy = dummy->next->next;
        }
        //remove links


        temp=head;
         Node *newhead = new Node(-1);
        dummy=newhead;
        dummy->next=temp->next;
        dummy=dummy->next;
        while(temp!=nullptr)
        {
            temp->next=temp->next->next;
            if(dummy->next)
            dummy->next=dummy->next->next;
            temp=temp->next;
            dummy=dummy->next;

        }
         return newhead->next;
    }
};