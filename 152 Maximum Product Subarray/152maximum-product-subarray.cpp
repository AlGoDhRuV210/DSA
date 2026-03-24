class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int ans=INT_MIN;
        int pre=1;
        int suf=1;
        for(int i =0;i<nums.size();i++)
        {
            (pre==0) ? pre=1 : pre+=0;
            (suf==0) ? suf=1 : pre+=0;
            pre*=nums[i];
            suf*=nums[n-i-1];
            ans=max(ans,max(pre,suf));
        }

        return ans;
    }
};