class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int mini = prices[0];
        int prev = 0;
        for (int i = 1; i < n; i++) {
            int cur ;
            int cost = prices[i] - mini;
            if (cost > 0) {
                cur = prev + cost;
                mini = prices[i];
            } else {
                cur = prev;
                 mini = min(mini, prices[i]);
            }
            prev = cur;
        }

        return prev;;
    }
};