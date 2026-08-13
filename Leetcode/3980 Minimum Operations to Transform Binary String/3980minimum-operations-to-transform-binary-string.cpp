class Solution
{
public:
    int minOperations(string s1, string s2)
    {
        int ans = 0;
        int n = s1.length();
        for (int i = 0; i < n; i++)
        {
            /* code */
            if (s1[i] == '0' && s2[i] == '1')
            {
                s1[i] = '1';
                ans++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '1' && s2[i] == '0')
            {
                if (i == n - 1)
                {
                    if (n == 1)
                        return -1;
                    ans += 2;
                }
                else if (s1[i + 1] == '1' && s2[i + 1] == '0')
                {
                    ans++;
                    i++;
                }
                else if (s1[i + 1] == '1' && s2[i + 1] == '1')
                {
                    ans += 2;
                    i++;
                }
                else if (s1[i + 1] == '0')
                    ans += 2;
            }
        }
        return ans;
    }
};