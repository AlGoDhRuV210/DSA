class Solution {
public:
//subarrays with less then or euqual to k odd numbers on it.
   int fun(vector<int>& nums, int k)
   {
    int cnt = 0;
    int ans = 0;
    int odd=0;
    int l =0;
    for(int i =0;i<nums.size();i++)
    {
        if(nums[i] & 1) odd++;
        if(odd>k)
        {
            while(odd>k)
            {
              if(nums[l] & 1) odd--;
              l++;   
            }
        }
        cnt+=i-l+1;

    }
    return cnt;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};