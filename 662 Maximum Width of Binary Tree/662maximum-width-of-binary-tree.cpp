/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    long long ans = 1;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0LL});
        int index = 0;
        while (!q.empty()) {
            int s = q.size();
            long long mn = INT_MAX;
            long long mx = INT_MIN;
            long long first = q.front().second;
            for (int i = 0; i < s; i++) {
                auto top = q.front();
                q.pop();
                mn = min(mn, top.second);
                mx = max(mx, top.second);
                if (top.first->left) {
                    q.push({top.first->left, (top.second - first) * 2 + 1});
                }
                if (top.first->right) {
                    q.push({top.first->right, (top.second - first) * 2 + 2});
                }
            }
            ans = max(ans, mx - mn + 1LL);
        }
        return int(ans);
    }
};