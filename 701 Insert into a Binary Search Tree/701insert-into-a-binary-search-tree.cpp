class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *node = new TreeNode(val);
        TreeNode *cur = root;
        if (!cur)
            return node;
        while (cur)
        {
            if (cur->val < val)
            {
                if (cur->right)
                    cur = cur->right;
                else
                {
                    cur->right = node;
                    break;
                }
            }
            else
            {
                if (cur->left)
                    cur = cur->left;
                else
                {
                    cur->left = node;
                    break;
                }
            }
        }

        return root;
    }
};