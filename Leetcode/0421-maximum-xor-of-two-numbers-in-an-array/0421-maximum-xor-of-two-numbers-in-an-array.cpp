struct Node {
    Node* links[2] = {nullptr};
    bool flag = false;

    bool containskey(int c) { return (links[c] != nullptr); }

    void put(int c) { links[c] = new Node; }
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int n) {
        Node* node = root;
        for (int i = 30; i >= 0; i--) {
            bool k = ((1 << i) & n);
            int ele =( k == true);
            if (!node->containskey(ele)) {
                node->put(ele);
            }
            node = node->links[ele];
        }
    }

    int check(int x) {
        int ans = 0;
        Node* node = root;
        for (int i = 30; i >= 0; i--) {
            bool k =( (1 << i) & x);
            int ele = 1 - (k == true);
            bool flag = true;
            if (!node->containskey(ele)) {
                ele = 1 - ele;
                flag = false;
            }
            node = node->links[ele];
            if(flag)
            ans = (ans | (1 << i));
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie t;
        for (auto i : nums)
            t.insert(i);
        int ans = 0;
        for (auto i : nums) {
            ans = max(ans, t.check(i));
        }
        return ans;
    }
};