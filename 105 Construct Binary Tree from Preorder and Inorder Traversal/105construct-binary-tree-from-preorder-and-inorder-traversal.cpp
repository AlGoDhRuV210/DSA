/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *ans = nullptr;
    unordered_map<int, int> mpp;

    void helper(vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instrt, int inend, TreeNode *&cur)
    {
        if (prestart > preend || instrt > inend)
            return;

        TreeNode *root = new TreeNode(preorder[prestart]);
        cur = root;
        int numleft = mpp[root->val] - instrt;
        // set left part

        helper(preorder, inorder, prestart + 1, prestart + numleft, instrt, mpp[root->val] - 1, cur->left);
        // set right
        helper(preorder, inorder, prestart + numleft + 1, preend, mpp[root->val] + 1, inend, cur->right);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode *cur = ans;

        helper(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1, ans);
        return ans;
    }
};