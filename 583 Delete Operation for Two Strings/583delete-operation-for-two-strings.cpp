class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<int> prev(n2 + 1);

        int last;
        // intitialse 0th row
        for (int j = 0; j <= n2; j++)
            prev[j] = j;

        // ,,..
        for (int i = 1; i <= n1; i++) {
            int diag = prev[0];
            prev[0] = i;
            for (int j = 1; j <= n2; j++) {
                last = prev[j];
                if (word1[i - 1] == word2[j - 1])
                    prev[j] = diag;
                else
                    prev[j] = 1 + min(prev[j], prev[j - 1]);
                diag = last;
            }
        }

        return prev[n2];
    }
};