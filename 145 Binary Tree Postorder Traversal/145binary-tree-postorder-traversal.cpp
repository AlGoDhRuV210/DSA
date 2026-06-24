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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (root == nullptr)
            return {};
        stack<TreeNode *> s1;
        TreeNode *cur = root;
        while (!s1.empty() || cur)
        {
            if (cur)
            {
                s1.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp = s1.top();
                if (temp->right)
                {
                    cur = temp->right;
                }
                else
                {
                    s1.pop();
                    v.push_back(temp->val);
          while (!s1.empty() && temp == s1.top()->right)
                    {
                        temp = s1.top();
                        s1.pop();
                        v.push_back(temp->val);
                    }
                }
            }
        }

        return v;
    }
};