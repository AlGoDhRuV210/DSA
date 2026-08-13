class Solution {
public:
    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {
        int n = monsters.size();
        int m = boosts.size();
        // vector<vector<int>> b;
        // vector<int> bonus(n, 0);
        // if (m >= 1)
        //     b.push_back(boosts[0]);
        // sort(boosts.begin(), boosts.end());
        // for (int i = 1; i < m; i++) {
        //     /* code */
        //     int l = boosts[i][0];
        //     int r = boosts[i][1];
        //     int v = boosts[i][2];
        //     if (b.back()[1] < l) {
        //         b.push_back({l, r, v});
        //     } else if (b.back()[1] == l) {
        //         b.back()[2]--;
        //         b.push_back({l, l, v + b.back()[2]});
        //     } else {
        //         int a = b.back()[0];
        //         int c = b.back()[1];
        //         int d = b.back()[2];
        //         b.pop_back();
        //         b.push_back({a, l, d});
        //         b.push_back({l, c, d + v});
        //         b.push_back({c, r, v});
        //     }
        // }
        long long low = 0;
        long long high = accumulate(monsters.begin(), monsters.end(), 0LL);
        long long ans = high;
        // for (auto i : b) {
        //     int l = i[0];
        //     int r = i[1];
        //     int v = i[2];
        //     for (int j = l; j <= r; j++)
        //         bonus[j] += v;
        // }
        // Difference array to compute bonus at each index

        vector<long long> diff(n + 1, 0);

        for (auto& b : boosts) {

            int l = b[0];

            int r = b[1];

            long long v = b[2];

            diff[l] += v;

            if (r + 1 < n)

                diff[r + 1] -= v;
        }

        vector<long long> bonus(n);

        long long curBonus = 0;

        for (int i = 0; i < n; i++) {

            curBonus += diff[i];

            bonus[i] = curBonus;
        }
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cur = mid;
            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (cur + bonus[i] >= monsters[i]) {
                    cur -= monsters[i];
                    if (cur < 0)
                        cur = 0;
                } else {
                    low = mid + 1;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};