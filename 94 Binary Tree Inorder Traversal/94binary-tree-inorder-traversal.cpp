class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return {};
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                ans.push_back(cur->val);
                cur = cur->right;
                continue;
            }

            TreeNode *temp = cur->left;
            while (temp->right && temp->right != cur)
                temp = temp->right;
            if (temp->right == cur)
            {
                ans.push_back(cur->val);
                temp->right = nullptr;
                cur = cur->right;
            }
            else
            {
                temp->right = cur;
                cur = cur->left;
            }
        }

        return ans;
    }
};