class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int flag=0;
        for(int i =0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    for(int k = j+1;k<nums.size();k++)
                    {
                        if(nums[k]==nums[j])
                        {int d=2*k - 2*i;
                        flag=1;
                        ans=min(ans,d);}
                    }
                }
            }
        }
         if(flag==0) return -1;
        return ans;
    }
};