class Solution
{
public:
  vector<string> createGrid(int m, int n)
  {
    if (m == 1)
    {
      string m = "";
      for (int i = 0; i < n; i++)
      {
        m += ".";
      }

      return {m};
    }
    if (n == 1)
    {
      vector<string> s(m, ".");
      return s;
    }
    vector<string> s(m, "");
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
      string q = "";
      for (int k = 0; k < min(n,cnt); k++)
      {
        q += "#";
      }
      
      for (int j = 0; j < min(2, n - cnt); j++)
      {
        q += ".";
      }
      
      {
        for (int j = 0; j < min(n,n - cnt - 2); j++)
        {
          if(i==m-1) q+=".";
          else
          q += "#";
        }
      }
      
      cnt++;
      if(cnt==n)
      {
        cnt--;

      }
     
      s[i] = q;
    }
    return s;
  }
};