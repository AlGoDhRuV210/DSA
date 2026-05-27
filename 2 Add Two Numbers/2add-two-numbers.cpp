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
     ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=new ListNode();
        ListNode* head=head1;

        // ListNode* h1=l1;
        // ListNode* h2=l2;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry)
        {
            int sum =carry;
            if(l1!=nullptr){ sum+=l1->val; l1=l1->next;}
            if(l2!=nullptr){ sum+=l2->val; l2=l2->next;}
            if(sum>9) 
            {
                ListNode* newnode=new ListNode(sum%10);
                head->next=newnode;
                head=head->next;
                carry=1;
            }
            else
            {
                 ListNode* newnode=new ListNode(sum);
                head->next=newnode;
                carry=0;
                 head=head->next;
            }

        }
    //     while(h1)
    //     {
          
    //          int sum =h1->val+carry;
    //           if(sum>9) 
    //         {
    //             ListNode* newnode=new ListNode(sum%10);
    //             head->next=newnode;
    //             head=head->next;
    //             carry=1;
    //         }
    //         else
    //         {
    //              ListNode* newnode=new ListNode(sum);
    //             head->next=newnode;
    //             carry=0;
    //              head=head->next;
    //         }
    //         h1=h1->next;
    //     }
    //    while(h2)
    //     {
          
    //          int sum =h2->val+carry;
    //           if(sum>9) 
    //         {
    //             ListNode* newnode=new ListNode(sum%10);
    //             head->next=newnode;
    //             head=head->next;
    //             carry=1;
    //         }
    //         else
    //         {
    //              ListNode* newnode=new ListNode(sum);
    //             head->next=newnode;
    //             carry=0;
    //              head=head->next;
    //         }
    //         h2=h2->next;
    //     }
        if(carry)
        {
             ListNode* newnode=new ListNode(1);
              head->next=newnode;
                  carry=0;
                 head=head->next;
        }
        return head1->next;

       

        
    }
};