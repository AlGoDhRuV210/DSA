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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        // level order traversal is required here
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                q.pop();
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                level.push_back(top->val);
            }
            if (cnt == 1) 
            {
                reverse(level.begin(), level.end());
                cnt = 0;
            } 
            else

            {
                cnt = 1;
            }
                ans.push_back(level);
        }
        return ans;
    }
};