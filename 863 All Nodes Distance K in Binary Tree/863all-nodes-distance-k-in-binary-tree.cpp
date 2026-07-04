/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    void markparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                if (top->left)
                {
                    q.push(top->left);
                    parent_track[top->left] = top;
                }
                if (top->right)
                {
                    q.push(top->right);
                    parent_track[top->right] = top;
                }
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (k == 0)
            return {target->val};
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markparent(root, parent_track);
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;
        while (k--)
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                if (top->left && visited.find(top->left) == visited.end())
                {
                    q.push(top->left);
                    visited[top->left] = true;
                }
                if (top->right && visited.find(top->right) == visited.end())
                {
                    q.push(top->right);
                    visited[top->right] = true;
                }
                if (parent_track.find(top) != parent_track.end() && visited.find(parent_track[top]) == visited.end())
                {
                    q.push(parent_track[top]);
                    visited[parent_track[top]] = true;
                }
            }
        }
        while (!q.empty())
        {
            TreeNode *top = q.front();
            q.pop();
            ans.push_back(top->val);
        }
        return ans;
    }
};
