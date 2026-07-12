class Solution
{
public:
    unordered_map<int, int> mpp;
    int n;
    bool dfs(int i, int color, vector<vector<int>> &graph)
    {
        mpp[i] = color;

        for (auto node : graph[i])
        {
            if (mpp[node] == color)
                return false;
            if (mpp[node] == -1)
            {
                if (dfs(node, 1 - color, graph) == false)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        for (int i = 0; i < n; i++)
        {
            mpp[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (mpp[i] == -1)
            {
                if (dfs(i, 0, graph) == false)
                    return false;
            }
        }

        return true;
    }
};