class Solution
{
public:
    TreeNode *root = nullptr;
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 1;


        helper(preorder, 0, preorder.size() - 1, root);

        return root;
    }

    void helper(vector<int> &preorder, int root, int end, TreeNode *&cur)
    {
        if (root > end)
        {
            cur = nullptr;
            return;
        }
        cur = new TreeNode(preorder[root]);
        // opreatre left
        int rightstart = root + 1;

        while (rightstart <= end && preorder[rightstart] < preorder[root])

            rightstart++;

        helper(preorder, root + 1, rightstart - 1, cur->left);

        helper(preorder, rightstart, end, cur->right);
    }
};
