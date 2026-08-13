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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        DisjointSet ds(n);
        for (auto i : connections)
        {
            ds.unionBySize(i[0], i[1]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findParent(i) == i)
                cnt++;
        }
        return cnt - 1;
    }
};