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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mpp.find(accounts[i][j]) == mpp.end())
                    mpp[accounts[i][j]] = i;
                else
                    ds.unionBySize(i, mpp[accounts[i][j]]);
            }
        }

        vector<string> mergedaccount[n];
        for (auto it : mpp)
        {
            string acc = it.first;
            int node = ds.findParent(it.second);
            mergedaccount[node].push_back(acc);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedaccount[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedaccount[i].begin(),mergedaccount[i].end());
            for (auto m : mergedaccount[i])
                temp.push_back(m);
            ans.push_back(temp);
        }
        return ans;
    }
};