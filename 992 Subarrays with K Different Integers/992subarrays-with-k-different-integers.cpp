class Solution {
public:
  int fun(vector<int>& nums, int k)
  {
    // no of subarrays with <= k integers
    unordered_map<int,int> mpp;
    int ans =0;
    int l =0;
    for (int i = 0; i < nums.size(); i++)
    {
      mpp[nums[i]]++;
      if(mpp.size()>k)
      {
        while(mpp.size()>k)
        {
          mpp[nums[l]]--;
          if(mpp[nums[l]]==0) mpp.erase(nums[l]);
          l++;
        }
      }
      ans+=i-l+1;

    }
    return ans;
    
  }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k==1) return fun(nums,k);
        return fun(nums,k)-fun(nums,k-1);
    }
};