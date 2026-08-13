/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        // if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
       
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==nullptr || head->next==nullptr) return true;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* newhead = reverse(slow->next);
          ListNode* temp1=head;
          ListNode* temp2=newhead;
        while(temp2!=nullptr)
        {
            if(temp2->val!=temp1->val) return 0;
            temp2=temp2->next; temp1=temp1->next;
        }
        reverse(newhead);
        return 1;
       
    }
};