class Solution {
public:
    int col[4] = {1, 0, -1, 0};
    int row[4] = {0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (i == m - 1 && j == n - 1)
                return diff;
            for (int d = 0; d < 4; d++) {
                int newrow = i + row[d];
                int newcol = j + col[d];
                if (newrow < 0 || newcol < 0 || newrow >= m || newcol >= n)
                    continue;
                int newval = heights[newrow][newcol];
                int newdis = max(diff, abs(newval - heights[i][j]));
                if (newdis < dist[newrow][newcol]) {
                    dist[newrow][newcol] = newdis;
                    pq.push({newdis, {newrow, newcol}});
                }
            }
        }
        return 0;
    }
};