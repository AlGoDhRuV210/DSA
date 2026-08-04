class Solution {
public:
    static bool comparator(string &a, string &b) {
    return a.size() < b.size();
}
    bool check(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if ((n2 - n1) != 1)
            return false;

        int i = 0, j = 0;
        bool ok = false;
        while (i < n1 && j < n2) {
            if (word1[i] == word2[j]) {
                i++;
                j++;
                continue;
            }
            if (!ok) {
                ok = true;
                j++;
                continue;
            }
            if (ok)
                return false;
        }
        if (j == n2)
            return true;

        if (ok)
            return false;

        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i]) && (dp[i] < dp[j] + 1)) {
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;
    }
};