class Solution
{
public:
    string ans;
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        for (int i = 0; i < n2; i++)
        {
            dp[0][i] = (text2.find(text1[0]) != string::npos &&
                        text2.find(text1[0]) <= i);
        }

        for (int i = 0; i < n1; i++)
        {
            dp[i][0] = (text1.find(text2[0]) != string::npos &&
                        text1.find(text2[0]) <= i);
        }

        for (int i = 1; i < n1; i++)
        {
            for (int j = 1; j < n2; j++)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                    ans = max(ans, 1 + dp[i - 1][j - 1]);

                ans = max(ans, dp[i][j - 1]);
                ans = max(ans, dp[i - 1][j]);

                dp[i][j] = ans;
            }
        }
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0)
        {
            if (text1[i] == text2[j])
            {
                ans = text1[i] + ans;
                i--;
                j--;
            }
            else
            {
                if (i - 1 >= 0 && (j == 0 || dp[i - 1][j] > dp[i][j - 1]))
                    i--;
                else
                    j--;
            }
        }
        // while (i >= 0)
        // {
        //     ans = text1[i] + ans;
        //     i--;
        // }

        // while (j >= 0)
        // {
        //     ans = text2[j] + ans;
        //     j--;
        // }

        return dp[n1 - 1][n2 - 1];
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        int len = longestCommonSubsequence(str1, str2);
        string scsub = "";
        int i = 0,j=0;
        for (char c : ans)
        {
            while (str1[i] != c)

                scsub += str1[i++];
            while (str2[j] != c)
                scsub += str2[j++];

            scsub += c;
            i++;
            j++;
        }
        while (i < str1.size())
            scsub += str1[i++];

        while (j < str2.size())
            scsub += str2[j++];

        return scsub;
    }
};