class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        int l = 0, r = 0;
        if (s == t)
            return s;
        unordered_map<char, int> mpp, tmap;
        vector<int> v(256, 0);

        for (auto i : t)
        {
            v[i]++;
            tmap[i]++;
        }
        string ans = "";
        while (r < m)
        {
            mpp[s[r]]++;
            if (tmap.find(s[r]) != tmap.end())
            {
                tmap[s[r]]--;
                if (tmap[s[r]] == 0)
                    tmap.erase(s[r]);
            }
            if (tmap.size() == 0)
            {
                // while (v[s[l]] == 0 || mpp[s[l]] > v[s[l]])
                while ( mpp[s[l]] >= v[s[l]])
                {
                    if (mpp[s[l]] == v[s[l]])
                        break;

                    mpp[s[l]]--;

                    if (mpp[s[l]] == 0)
                        mpp.erase(s[l]);

                    l++;
                }

                if (ans.empty() || r - l + 1 < ans.size())
                {
                    ans = s.substr(l, r - l + 1);
                }

                mpp[s[l]]--;

                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);

                tmap[s[l]]++;
                l++;
            }

            r++;
        }
        return ans;
    }
};