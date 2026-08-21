#include<bits/stdc++.h>
class Solution {
public:
    
    long long solve(long long mid, vector<int>& coins, vector<long long>& lcms,
                    int k) {
        int m = lcms.size();
        int n = coins.size();
        long long cnt = 0;
        for (int i = 1; i < m; i++) {
            if (lcms[i] > mid)
                continue;
            if (__builtin_popcount(i) & 1)
                cnt += (mid) / lcms[i];
            else
                cnt -= (mid) / lcms[i];
        }
        return cnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        if (k == 1)
            return coins[0];
        vector<int> v;
        for (auto i : coins) {
            bool flag = 1;
            for (auto j : v) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                v.push_back(i);
        }

        long long low = k;
        long long high = 1LL * v[0] * k + 1;

        int m = (1 << v.size());
        vector<long long> lcms(m, 1);

        for (int i = 1; i < m; i++) {
            long long temp = i;
            long long cur = 1;
            long long cnt = 0;
            while (temp > 0) {
                if (temp & 1) {
                    cur = lcm(cur, v[cnt]);
                }
                cnt++;
                temp = temp >> 1;
                if (cur > high) {
                    cur = high + 1;
                    break;
                }
            }
            lcms[i] = cur;
        }
        int ans = high;
        while (low <= high) {
            long long mid = (low) + (high - low) / 2;
            if (solve(mid, coins, lcms, k) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};