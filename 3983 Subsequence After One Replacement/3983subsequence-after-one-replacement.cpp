class Solution
{
public:
    bool canMakeSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        if (n > m)
            return false;

        vector<int> suffix(n+1, m);

        int i = n - 1, j = m - 1;

        while (i >= 0)
        {
            while (j >= 0 && s[i] != t[j])
                j--;

            if (j >= 0)
                suffix[i] = j;
            i--;
            j--;
        }
        i = 0;
        j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                if (i == n - 1)
                    return true;

                if (j < suffix[i + 1] && suffix[i+1]!=m)
                    return true;

                j++;
            }
        }
        if (i >= n)
            return true;
       return (i == n - 1 && j < m);
    }
};