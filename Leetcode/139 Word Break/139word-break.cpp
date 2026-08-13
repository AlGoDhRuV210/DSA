class Solution {
public:

   bool solve(string s,   unordered_set<string> &m,int index,vector<int> &dp)
   {
    if(index==s.length()) return true;
    if(dp[index]!=-1) return dp[index];

     string cur="";
    for (int i = index; i < s.length(); i++)
    {
        cur+=s[i];

       if(m.find(cur)!=m.end())
       {
        if(solve(s, m, i + 1, dp))
         return dp[index] = true;
       }
    }
       return dp[index]= false;
    


   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        for(auto i : wordDict)
         m.insert(i);
         vector<int> dp(s.length(),-1);
         return solve(s,m,0,dp);
    }
};



