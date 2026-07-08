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
    int minn(TreeNode* root) {
        if (!root)
            return INT_MAX;
        return min(root->val, minn(root->left));
    }
    int maxx(TreeNode* root) {
        if (!root)
            return INT_MIN;
        return max(root->val, maxx(root->right));
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        if (!root->right && !root->left)
            return true;
        if (root->right) {
            if (root->right->val <= root->val)
                return false;
            if (root->val >= minn(root->right))
                return false;
        }
        if (root->left) {
            if (root->left->val >= root->val)
                return false;
            if (root->val <= maxx(root->left))
                return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};