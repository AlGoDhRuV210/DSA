class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

    static bool check(vector<int> &a, int x) { return a[1] < x; }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> v(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int w = intervals[i][2];
            int id = intervals[i][3];

            int k = lower_bound(intervals.begin(), intervals.begin() + i,
                                vector<int>{0, l, 0, 0},
                                [](vector<int> a, vector<int> b) {
                                    return a[1] < b[1];
                                }) -
                    intervals.begin();

            for (int j = 1; j <= 4; j++) {
                long long x = dp[i][j];
                long long y = dp[k][j - 1] + w;

                if (x > y) {
                    dp[i + 1][j] = x;
                    v[i + 1][j] = v[i][j];
                } else {
                    vector<int> z = v[k][j - 1];
                    z.push_back(id);
                    sort(z.begin(), z.end());

                    if (x == y && v[i][j] < z) {
                        z = v[i][j];
                    }

                    dp[i + 1][j] = y;
                    v[i + 1][j] = z;
                }
            }
        }

        return v[n][4];
    }
};