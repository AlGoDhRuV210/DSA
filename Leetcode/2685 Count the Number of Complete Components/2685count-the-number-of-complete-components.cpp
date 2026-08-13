class Solution
{
public:
    int edge = 0, v = 0;
    int ans = 0;

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
      edge += adj[node].size();
        v++;
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            edge = 0, v = 0;

            if (!vis[i])
            {
                dfs(i, adj, vis);
                edge /= 2;
                if (edge == ((v * (v - 1)) / 2))
                    ans++;
            }
        }

        return ans;
    }
};