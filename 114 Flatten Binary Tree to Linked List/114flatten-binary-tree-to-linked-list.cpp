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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        stack<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* top = q.top();
            q.pop();
            if (top->right)
                q.push(top->right);
            if (top->left)
                q.push(top->left);
            if(!q.empty())
            {top->right = q.top();}
            top->left = nullptr;
        }
    }
};