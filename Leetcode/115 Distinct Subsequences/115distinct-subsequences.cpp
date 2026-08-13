class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();
        // vector<vector<unsigned int>> dp(n2 + 1, vector<unsigned int>(n1 + 1, 0));
        vector<unsigned int> prev(n2+1, 0) ;
        // if (s[0] == t[0])
            prev[0] = 1;
        // for (int i = 0; i <= n2; i++)
        //     prev[i] =1 ;

        for (int i = 1; i <= n1; i++)
        {
            /* code */
            // char c = t[i - 1];
            for (int j = n2; j >=1; j--)
            {

                if (t[j-1] == s[i - 1])
                    prev[j] = prev[j - 1] + prev[j];
                // else
                //     cur[j] = cur[j - 1];
            }
            // prev = cur;
        }
        return prev[n2];
    }
};