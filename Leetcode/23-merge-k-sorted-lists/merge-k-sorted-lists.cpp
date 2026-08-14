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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for (int i = 0; i < n; i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        while (!pq.empty()) {
            auto top = pq.top();
            int ele = top.first;
            pq.pop();
            temp->next = new ListNode(ele);
            if (top.second->next)
                pq.push({top.second->next->val, top.second->next});
            temp = temp->next;
        }

        return dummy->next;
    }
};
