class DisjointSet
{
private:
public:
    vector<int> parent, rank, size;
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
    int col[4] = {0, 1, -1, 0};
    int row[4] = {1, 0, 0, -1};
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n*n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                int node = i * n + j;

                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + row[k];
                    int ncol = j + col[k];
                    int newnode = nrow * n + ncol;
                    if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n)
                        continue;
                    if (grid[nrow][ncol] == 1)
                        ds.unionBySize(node, newnode);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                int cursize = 1;
                set<int> s;
                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + row[k];
                    int ncol = j + col[k];
                    int newnode = nrow * n + ncol;
                    if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n)
                        continue;

                    if (grid[nrow][ncol] == 0)
                        continue;
                     int par = ds.findParent(newnode);
                    if (s.find(par) == s.end())
                    {
                        s.insert(par);
                        cursize += ds.size[par];
                    }
                }
                ans = max(ans, cursize);
            }
        }
        
        bool all1 = true;
        bool all0 = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    all1 = false;
                else
                    all0 = false;
            }
        }
        if (all1)
            return n * n;
        else if(all0)
            return 1;
        else 
        return ans;
    }
};