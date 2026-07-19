class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        // each node has {to , time};
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<long long> timetaken(n, LLONG_MAX);

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        //{time,node}
        timetaken[0LL] = 0;
        vector<long long> ways(n, 0);
        ways[0LL] = 1;
        int mod = (int)(1e9 + 7);

        pq.push({0LL, 0LL});
        while (!pq.empty())
        {
            long long  curtime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i : adj[node])
            {
                int time = i.second;
                int newnode = i.first;
                if (timetaken[newnode] > curtime + time)
                {
                    timetaken[newnode] = curtime + time;
                    ways[newnode] = ways[node];
                    pq.push({curtime + time, newnode});
                }
                else if (timetaken[newnode] == curtime + time)
                    ways[newnode] = (ways[newnode] + ways[node]) % mod;
            }
        }

        return ways[n - 1] % mod;
    }
};