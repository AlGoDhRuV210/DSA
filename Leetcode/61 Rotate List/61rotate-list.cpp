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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;

        if(head==nullptr || head->next==nullptr) return head;
        int l =1;
        while(temp->next != nullptr) {l++; temp=temp->next;};
        k=k%l;
        int tail = l-k;
        temp->next=head;
        temp=head;
        tail--;
        while(tail--)
        {
            temp=temp->next;
        }
       
        head =temp->next;
        temp->next=nullptr;
        return head;

        
    }
};