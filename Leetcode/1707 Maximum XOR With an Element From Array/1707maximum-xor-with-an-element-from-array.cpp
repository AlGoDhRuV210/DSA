
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
            int ele = (k == true);
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
            bool k = ((1 << i) & x);
            int ele = 1 - (k == true);
            bool flag = true;
            if (!node->containskey(ele)) {
                ele = 1 - ele;
                flag = false;
            }
            node = node->links[ele];
            if (flag)
                ans = (ans | (1 << i));
        }
        return ans;
    }
};
class Solution {
public:
    static bool comparator(vector<int>& p1, vector<int>& p2) {
        return p1[1] < p2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        map<pair<int, int>, vector<int>> mpp;
        for (int i = 0; i < m; i++) {
            mpp[{queries[i][0], queries[i][1]}].push_back(i);
        }
        Trie t;
        int i = 0;
        sort(queries.begin(), queries.end(), comparator);
        sort(nums.begin(), nums.end());
        int j = 0;
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int maxele = queries[i][1];
            int x = queries[i][0];
            int cur = 0;
            while (j < n && nums[j] <= maxele) {
                t.insert(nums[j]);
                j++;
            }
            if (j == 0) {
                for (auto h : mpp[{x, maxele}])
                ans[h] = -1;
                continue;
            }
            cur = t.check(x);
            for (auto h : mpp[{x, maxele}])
                ans[h] = cur;
        }
        return ans;
    }
};