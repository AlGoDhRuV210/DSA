#include <bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>& nums, int skip) {
        int cur = 0;
        int n = nums.size();
        vector<int> t = nums;
        t.erase(t.begin() + skip);
        vector<int> l(n - 1), r(n - 1);
        l[0] = t[0];
        r[n - 2] = t[n - 2];
        for (int i = 1; i < n - 1; i++)
            l[i] = __gcd(l[i - 1], t[i]);
        for (int i = n - 3; i >= 0; i--)
            r[i] = __gcd(r[i + 1], t[i]);
        for (int i = 0; i < n - 2; i++)
            if (l[i] == r[i + 1])
                cur++;

        return cur;
    }
    int maxValidSplits(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> l(n), r(n);
        l[0] = nums[0];
        r[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            l[i] = __gcd(l[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)
            r[i] = __gcd(r[i + 1], nums[i]);
        for (int i = 1; i < n; i++) {
            if (l[i] != l[i - 1])
                ans = max(ans, solve(nums, i));
        }
        for (int i = n - 2; i >= 0; i--) {
            if (r[i] != r[i + 1])
                ans = max(ans, solve(nums, i));
        }
        // remove no index
        int cur = 0;
        for (int i = 0; i < n - 1; i++)
            if (l[i] == r[i + 1])
                cur++;
        ans = max(ans, cur);

        return ans;
    }
};