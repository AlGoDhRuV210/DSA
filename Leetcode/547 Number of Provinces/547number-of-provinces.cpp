class Solution {
public:
    // void help(vector<vector<int>>& adj, vector<int>& visited, int node, ) {}
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int start) {

        visited[start] = 1;
        // help(adj, visited, start);
        for (int i = 0; i < adj.size(); i++) {
            if (adj[start][i] == 1 && !visited[i]) {
                visited[i] = 1;
                dfs(adj, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> visited(isConnected.size(), 0);
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
};