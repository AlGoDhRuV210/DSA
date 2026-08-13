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
    int ans = 0;
    TreeNode* startNode = nullptr;
    void markparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track,int start) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                q.pop();
                if (top->val == start)

                    startNode = top;
                if (top->left) {
                    q.push(top->left);
                    parent_track[top->left] = top;
                }
                if (top->right) {
                    q.push(top->right);
                    parent_track[top->right] = top;
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparent(root, parent_track,start);
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        if (!root->left && !root->right)
            return 0;
        while (!q.empty()) {
            int flag = 0;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                q.pop();
                if (top->left && visited.find(top->left) == visited.end()) {
                    flag = 1;
                    q.push(top->left);
                    visited[top->left] = true;
                }
                if (top->right && visited.find(top->right) == visited.end()) {
                    flag = 1;
                    q.push(top->right);
                    visited[top->right] = true;
                }
                if (parent_track.find(top) != parent_track.end() &&
                    visited.find(parent_track[top]) == visited.end()) {
                    flag = 1;
                    q.push(parent_track[top]);
                    visited[parent_track[top]] = true;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};