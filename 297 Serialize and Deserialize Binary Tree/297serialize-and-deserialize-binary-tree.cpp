/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string s = "";
        string temp = to_string(root->val);
        s += temp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                TreeNode* top = q.front();
                q.pop();
                s += ",";
                if (top->left) {
                    q.push(top->left);
                    temp = to_string(top->left->val);
                    s += temp;
                } else
                    s += "n";

                s += ",";
                if (top->right) {
                    q.push(top->right);
                    temp = to_string(top->right->val);
                    s += temp;
                } else
                    s += "n";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s == "")
            return nullptr;
        int i = 0;
        int n = s.length();
        while (i < n && s[i] != ',')
            i++;

        int value = stoi(s.substr(0, i));
        TreeNode* root = new TreeNode(value);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
             
                TreeNode* top = q.front();

                q.pop();
                i++;
                if (i >= n)
                    return root;
                ;

                int last = i;
                while (i < n && s[i] != ',')
                    i++;
                if (s[last] != 'n') {
                    top->left = new TreeNode(stoi(s.substr(last, i - last)));
                    q.push(top->left);
                }
                i++;
                if (i >= n)
                    return root;
                ;
                last = i;
                while (i < n && s[i] != ',')
                    i++;
                if (i >= n)
                    return root;
                ;
                if (s[last] != 'n') {
                    top->right = new TreeNode(stoi(s.substr(last, i - last)));
                    q.push(top->right);
                }
            }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));