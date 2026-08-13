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
     ListNode* merge(ListNode* head,ListNode* middle)
     {
        ListNode* newhead=new ListNode(-1);
        ListNode* temp=newhead;
        while(head!=nullptr && middle!=nullptr)
        {
            if(head->val <= middle->val)
            {
                temp->next=head;
                head=head->next;
            }
            else 
            {
                 temp->next=middle;
                middle=middle->next;
            }
            temp=temp->next;
        }
        while(head) { temp->next=head;
                head=head->next;
                temp = temp->next;}
                while(middle)
          {
                 temp->next=middle;
                middle=middle->next;
                temp = temp->next;
          }
          return newhead->next;
                
     }
        

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
          ListNode* slow = head; 
           ListNode* fast = head; 
           ListNode* prev = nullptr; 
    while (fast != NULL && fast->next != NULL) {
        prev=slow;
        slow = slow->next; 
        fast = fast->next->next; 
    }
     ListNode* middle=slow;
     prev->next=nullptr;
     return merge(sortList(head),sortList(middle));

    }
};