class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, int par, int t, vector<vector<int>>& adj,
             vector<int>& vis, int tin[], int low[]) {
        tin[node] = t;
        low[node] = t;
        vis[node] = 1;
        t++;
        for (auto i : adj[node]) {
            if (i == par)
                continue;
            if (vis[i]) {
                low[node] = min(low[node], low[i]);
            } else {
                dfs(i, node, t, adj, vis, tin, low);
                low[node] = min(low[node], low[i]);
                // check if bridge
                if (low[i] > tin[node])
                    ans.push_back({i, node});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> adj(n, vector<int>());
        for (auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int tin[n];
        int low[n];
        vector<int> vis(n, 0);
        vis[0] = 1;
        dfs(0, -1, 1, adj, vis, tin, low);

        return ans;
    }
};