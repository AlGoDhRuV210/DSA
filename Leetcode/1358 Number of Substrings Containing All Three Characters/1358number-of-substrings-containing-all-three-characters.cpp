class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int ans = 0;
    int l = 0;
    int n = s.length();
    int r = 0;
    unordered_map<char, int> mpp;
    while (r < n)
    {
      mpp[s[r]]++;
      if (mpp.size() == 3)
      {
        while (mpp.size() == 3)
        {
          ans += n - r;
          mpp[s[l]]--;
          if (mpp[s[l]] == 0)
            mpp.erase(s[l]);
          l++;
        }
      }
      r++;
    }
    return ans;
  }
};