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
class BSTIterator
{
public:
    stack<TreeNode* > s;

    BSTIterator(TreeNode *root)
    {
        TreeNode *node = root;
        s.push(node);
        while (node->left)
        {
            s.push(node->left);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode *top = s.top();
        s.pop();
        int val = top->val;
        top=top->right;
        while (top)
        {
            s.push(top);
            top = top->left;
        }
        return val;
    }

    bool hasNext()
    {
        if (s.empty())
            return false;
        return true;
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */