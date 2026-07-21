class DisjointSet
{
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            for (int j = i + 1; j < n; j++)
            {
                if (x == stones[j][0] || y == stones[j][1])
                    ds.unionBySize(i, j);
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            if (ds.findParent(i) == i)
                components++;
        }
        return n - components;
    }
};