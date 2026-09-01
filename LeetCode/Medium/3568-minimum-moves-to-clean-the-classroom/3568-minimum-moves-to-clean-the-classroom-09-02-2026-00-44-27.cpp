class Solution {
public:
    int minMoves(vector<string>& a, int E) {
        int m = a.size(), n = a[0].size();
        int sx, sy, k = 0;

        vector<vector<int>> id(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') sx = i, sy = j;
                if (a[i][j] == 'L') id[i][j] = 1 << k++;
            }

        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        struct Node {
            int x, y, mask, e, steps;
        };

        queue<Node> q;
        q.push({sx, sy, 0, E, 0});
        best[sx][sy][0] = E;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur.mask == (1 << k) - 1)
                return cur.steps;

            if (cur.e == 0) continue;

            for (int d = 0; d < 4; d++) {
                int x = cur.x + dx[d];
                int y = cur.y + dy[d];

                if (x < 0 || x >= m || y < 0 || y >= n || a[x][y] == 'X')
                    continue;

                int e = (a[x][y] == 'R') ? E : cur.e - 1;
                int mask = cur.mask | id[x][y];

                if (e > best[x][y][mask]) {
                    best[x][y][mask] = e;
                    q.push({x, y, mask, e, cur.steps + 1});
                }
            }
        }

        return -1;
    }
};