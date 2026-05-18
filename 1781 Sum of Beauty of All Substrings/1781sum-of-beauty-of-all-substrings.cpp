
class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int> mpp;
        int ans = 0;
        int n = s.size();
        for (int i = 0;i<n;i++)
        {
            mpp.clear();
            mpp[s[i]]++;
            for (int j = i+1;j<n;j++)
          {
            mpp[s[j]]++;
            int mx=INT_MIN;
            int mn=INT_MAX;
            for(auto i : mpp) 
            {
                mx=max(mx,i.second);
                mn=min(mn,i.second);
            }
                ans+=mx-mn;
            
          }
            
        }
        return ans;
    }
};