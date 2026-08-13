class nodev
{
public:
    int mx, mn, sum;
    bool bst;
    nodev(int mx, int mn, int sum, bool bst)
    {

        this->mx = mx;
        this->mn = mn;
        this->sum = sum;
        this->bst = bst;
    }
};

class Solution
{
public:
    int ans = INT_MIN;
    nodev helper(TreeNode *root, int mx, int mn)
    {
        if (!root)
        {
            return nodev(INT_MIN, INT_MAX, 0, true);
        }
        nodev left = helper(root->left, root->val, mn);
        nodev right = helper(root->right, mx, root->val);
        if (left.bst && right.bst && root->val > left.mx && root->val < right.mn)
        {

            ans = max(ans, left.sum + right.sum + root->val);

            return nodev(max(right.mx, root->val), min(root->val, left.mn),
                         left.sum + right.sum + root->val, true);
        }
        return nodev(INT_MAX, INT_MIN, 0, false);
    }
    int maxSumBST(TreeNode *root)
    {
        helper(root, INT_MAX, INT_MIN);
        if (ans < 0)
            return 0;
        return ans;
    }
};