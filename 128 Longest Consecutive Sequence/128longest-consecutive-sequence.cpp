class Solution {
public:
    int longestConsecutive(vector<int>& nums)
      {
        unordered_set<int> s;
        int ans=0;
        for(auto i: nums)   s.insert(i);
        for(auto i : s)
        {
            if(s.find(i-1)==s.end())
            {
                int cnt=1;
                int x=i;
                while(s.find(x+1)!=s.end())
                {
                    cnt++;
                    x++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;

      }
};