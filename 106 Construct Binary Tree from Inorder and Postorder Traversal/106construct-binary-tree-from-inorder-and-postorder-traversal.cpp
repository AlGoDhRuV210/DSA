class Solution
{
public:
    TreeNode *ans = nullptr;
    unordered_map<int, int> mpp;

    void helper(vector<int> &preorder, vector<int> &inorder, int prestart,
                int preend, int instrt, int inend, TreeNode *&cur)
    {
        if (prestart > preend || instrt > inend)
            return;

        TreeNode *root = new TreeNode(preorder[prestart]);
        cur = root;
        int numleft = mpp[root->val] - instrt;
        // set right part

        helper(preorder, inorder, prestart + 1, prestart + numleft, instrt,
               mpp[root->val] - 1, cur->right);
        // set left
        helper(preorder, inorder, prestart + numleft + 1, preend,
               mpp[root->val] + 1, inend, cur->left);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        reverse(inorder.begin(), inorder.end());
        reverse(postorder.begin(), postorder.end());
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        TreeNode *cur = ans;

        helper(postorder, inorder, 0, postorder.size() - 1, 0,
               postorder.size() - 1, ans);
        return ans;
    }
};
