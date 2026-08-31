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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int cnt = 0;
        vector<int> p;
        int last = head->val;
        ListNode* temp = head->next;
        while (temp->next) {
            if ((temp->val > temp->next->val && temp->val > last) ||
                temp->val < temp->next->val && temp->val < last) {
                p.push_back(cnt);
            }
            cnt++;
            last = temp->val;
            temp = temp->next;
        }
        if (p.size() < 2)
            return {-1, -1};

        int mx = p.back() - p[0];
        int mn = p[1] - p[0];
        for (int i = 2; i < p.size(); i++) {
            mn = min(mn, p[i] - p[i - 1]);
        }
        return {mn, mx};
    }
};