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
class Solution {
public:
  int leftheight(TreeNode* root)
  {
    if(!root) return 0;
    int cnt = 0;
    while(root)
    {
        cnt++;
        root=root->left;
    }
    return cnt;
  }
  int rightheight(TreeNode* root)
  {
    if(!root) return 0;
    int cnt = 0;
    while(root)
    {
        cnt++;
        root=root->right;
    }
    return cnt;
  }

    int countNodes(TreeNode* root) {
        int lefth=leftheight(root);
        int righth=rightheight(root);
        if(lefth==righth) 
        return (1<<lefth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};