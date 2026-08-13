class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        // each node has {to , time};
        for (auto i : times)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> timetaken(n + 1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        //{time,node}

         timetaken[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            int curtime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto i : adj[node])
            {
                int time = i.second;
                int newnode = i.first;
                if (timetaken[newnode] > curtime + time)
                {
                    timetaken[newnode] = curtime + time;
                    pq.push({curtime + time, newnode});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            /* code */
            if (timetaken[i] == 1e9)
                return -1;
        }
        timetaken[0] = -1;
        return *max_element(timetaken.begin(), timetaken.end());
    }
};