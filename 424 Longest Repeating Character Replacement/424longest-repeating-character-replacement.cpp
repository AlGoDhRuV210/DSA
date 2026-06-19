class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxlen = 0;
        map<char, int> mpp;
        vector<int> v(26, 0);
        int l = 0;
        int mx = 0;

        for (int r = 0; r < s.length(); r++)
        {
            v[s[r] - 'A']++;
            mx = *max_element(v.begin(), v.end());
            while ((r - l + 1) - mx > k)
            {
                v[s[l] - 'A']--;
                l++;
            }
             
                maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};