class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> suffixmax(n);
        suffixmax[n-1]=nums[n-1];
        for (int i = n-2; i >=0; i--)
        {
            suffixmax[i]=max(suffixmax[i+1],nums[i]);
        }
        for (int i = 0; i <=n-1-k; i++)
        {
            ans=max(ans,nums[i]+suffixmax[i+k]);
        }
        return ans;
        
        
    }
};