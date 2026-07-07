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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            if (!root->left && !root->right)
                return nullptr;
            if (root->left) {
                if (!root->right) {
                    return root->left;
                }
                TreeNode* r = root->right;
                while (r->left)
                    r = r->left;
                r->left = root->left;
                return root->right;
            }
            return root->right;
        }
        TreeNode* cur = root;
        pair<TreeNode*, int> prev;
        while (cur) {
            if (cur->val > key) {
                prev = {cur, -1};
                cur = cur->left;
            } else if (cur->val < key) {
                prev = {cur, 1};
                cur = cur->right;
            } else {
                if (prev.second == -1)
                // operate left
                {
                    if (!cur->left && !cur->right) {
                        prev.first->left = nullptr;
                        return root;
                    }
                    TreeNode* r = cur->right;
                    TreeNode* l = cur->left;
                    prev.first->left = r;
                     if (!r) {
                        prev.first->left = cur->left;
                        return root;
                    }
                    while (r->left)
                        r = r->left;
                    r->left = l;
                    return root;
                } else // operate right
                {
                    if (!cur->left && !cur->right) {
                        prev.first->right = nullptr;
                        return root;
                    }
                    TreeNode* r = cur->right;
                    TreeNode* l = cur->left;
                    if (!r) {
                        prev.first->right = cur->left;
                        return root;
                    }
                    prev.first->right = r;
                    while (r->left)
                        r = r->left;
                    r->left = l;
                    return root;
                }
            }
        }
        return root;
    }
};