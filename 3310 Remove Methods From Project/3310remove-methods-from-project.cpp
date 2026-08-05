class Solution {
public:
    vector<int> ans;
    bool ok;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = -1;

        for (auto i : adj[node]) {
            if (vis[i] == 0)
                dfs(i, adj, vis);
        }
    }
    void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto i : adj[node]) {
            if (vis[i] == -1) {
                ok = true;
                return;
            }
            if (vis[i] != 1)
            dfs2(i, adj, vis);
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n); // adjacency list
        for (auto i : invocations)
            adj[i[0]].push_back(i[1]);
        vector<int> vis(n, 0);
        ok = false;

        dfs(k, adj, vis);

        for (int i = 0; i < n; i++) {
            /* code */
            if (vis[i] == 0)
                dfs2(i, adj, vis);
        }
       

        for (int i = 0; i < n; i++) {
            /* code */
            ans.push_back(i);
        }
        if (ok)
            return ans;

        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1)
                v.push_back(i);
        }
        return v;
    }
};