class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        int V = n;
        vector<int> dist(n, 1e9);
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        // each node has {to , price};
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        k++;

        queue<pair<int, int>> pq; // {node,price}
        dist[src] = 0;
        pq.push({src, 0});
        while (!pq.empty() && k--)
        {
            int sz = pq.size();
            for (int i = 0; i < sz; i++)
            {
                {
                    int curprice = pq.front().second;
                    int node = pq.front().first;
                    pq.pop();
                    for (auto i : adj[node])
                    {
                        int newcity = i.first;
                        int price = i.second;
                        if (dist[newcity] > price + curprice)
                        {
                            dist[newcity] = price + curprice;
                            pq.push({newcity, dist[newcity]});
                        }
                    }
                }
            }
        }
            if (dist[dst] == 1e9)
                return -1;
            return dist[dst];
    }
};