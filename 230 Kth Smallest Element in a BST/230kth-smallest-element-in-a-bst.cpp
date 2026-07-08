class Solution
{
public:
    int cnt = 0;
    int ans = -1;
    int kthSmallest(TreeNode *root, int k)
    {
        helper(root, k);
        return ans;
    }

    void helper(TreeNode *root, int k)
    {
        if (!root)
            return;

        helper(root->left, k);
        cnt++;
        if (k == cnt)
        {
            ans = root->val;
            return;
        }
        helper(root->right, k);
    }
};