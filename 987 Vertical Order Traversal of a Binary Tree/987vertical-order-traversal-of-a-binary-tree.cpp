/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mpp;
        while (!q.empty())
        {
            auto i = q.front();
            q.pop();
            mpp[i.second.first][i.second.second].insert(i.first->val);

            if (i.first->left)
                q.push({i.first->left, {i.second.first - 1, i.second.second + 1}});
            if (i.first->right)
                q.push({i.first->right, {i.second.first + 1, i.second.second + 1}});
        }
        for(auto i : mpp)
        {
            vector<int> v;
            for(auto j  : i.second)
            {
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};