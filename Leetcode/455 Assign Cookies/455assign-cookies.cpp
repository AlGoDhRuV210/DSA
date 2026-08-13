class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // s[i] can be given to g[i] if s[i]>=g[i]
        int m = g.size();
        int n = s.size();
        int i = 0; // on g
        int j = 0; // on s
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < m && j < n)
        {
            if (g[i] <= s[j])
            {
                ans++;
                i++;
                j++;
            }
            else
                j++;
        }
        return ans;
    }
};