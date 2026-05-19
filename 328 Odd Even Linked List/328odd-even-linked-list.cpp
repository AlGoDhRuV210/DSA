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
    ListNode* oddEvenList(ListNode* head) {
         if(head == nullptr || head->next == nullptr|| head->next->next==nullptr)
            return head;
        ListNode* odd=head;
        ListNode* temp=head->next;;
        ListNode* even=head->next;
        while(even!=nullptr && even->next!=nullptr )
        {
            odd->next=odd->next->next;
            odd=odd->next;

             even->next=even->next->next;
            even=even->next;
        }
        odd->next=temp;
        return head;

    }
};