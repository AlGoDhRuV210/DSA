class Solution {
public:
   int countValidPrefixes(string s)
    {
        int ones = 0;
        int zero = 0;
        int ans = 0;
        for (auto i : s)
        {
            if (i == '1')
                ones++;
            else
                zero++;

            if (abs(ones - zero) <= 1)
                ans++;
        }
        return ans;
    }
};