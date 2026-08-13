class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // n > m
        vector<int> dp(n + 1, 0);
        int i = n - 1;
        int j = m - 1;
        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            } else
                dp[i] = dp[i + 1];

            i--;
        }
        while (i >= 0) {
            dp[i] = dp[i + 1];
            i--;
        }

        vector<int> ans;
        j = 0;
        int skip = 0;
        for (int i = 0; i < n; i++) {
            if (j >= m)
                break;
            int rem = m - j - 1;
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else {
                if (dp[i + 1] >= rem && skip == 0) {
                    ans.push_back(i);
                    skip = 1;
                    j++;
                } 
            }
        }
        if (j < m)
            return {};
        return ans;
    }
};