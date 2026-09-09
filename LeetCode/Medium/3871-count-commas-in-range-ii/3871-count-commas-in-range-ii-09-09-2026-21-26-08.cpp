class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n < 1000)
            ans = 0;
        else if (n < (int)(1e6))
            ans = n - 1000 + 1;
        else if (n < (int)(1e9))
            ans = 2 * (n - 1e6 + 1) + (1e6 - 1e3);
        else if (n < (long long)(1e12))
            ans = 3 * (n - 1e9 + 1) + 2 * (1e9 - 1e6) + (1e6 - 1e3);
        else if (n < (long long)(1e15))
            ans = 4 * (n - 1e12 + 1) + 3 * (1e12 - 1e9) + 2 * (1e9 - 1e6) +
                  (1e6 - 1e3);
        else
            ans = 5 + 4 * (1e15 - 1e12) + 3 * (1e12 - 1e9) + 2 * (1e9 - 1e6) +
                  (1e6 - 1e3);
        return ans;
    }
};