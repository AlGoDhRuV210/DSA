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
int ans;
class Solution {
public:
    int val(TreeNode* root, int& cnt) {

        if (root == nullptr)
            return 0;
        cnt++;
        int l = val(root->left, cnt);
        int r = val(root->right, cnt) ;
        return root->val + l + r;
    }
    void solve(TreeNode* cur) {
        if (cur == nullptr)
            return;
        int cnt = 0;
        int x = val(cur, cnt);
        if (cur->val == (x / cnt))
            ans++;

        solve(cur->left);
        solve(cur->right);
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);

        return ans;
    }
};