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
    // int val(TreeNode* root, int& cnt) {

    //     if (root == nullptr)
    //         return 0;
    //     cnt++;
    //     int l = val(root->left, cnt);
    //     int r = val(root->right, cnt) ;
    //     return root->val + l + r;
    // }
    pair<int, int> solve(TreeNode* cur) {
        if (cur == nullptr)
            return {0, 0};
        auto l = solve(cur->left);
        auto r = solve(cur->right);

        int x = l.first + r.first + cur->val;
        int cnt = l.second + r.second + 1;
        if (cur->val == (x / cnt))
            ans++;
        
         
        return {x,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);

        return ans;
    }
};