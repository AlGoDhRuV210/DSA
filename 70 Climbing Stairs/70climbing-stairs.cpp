class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
        return n;
        // vector<int> dp(n + 1, -1);
        // dp[1] = 1;
        // dp[2] = 2;
    int prev = 2;
    int prev2=1;
    int cur ;
        for (int i = 3; i <= n; i++) {
            cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};