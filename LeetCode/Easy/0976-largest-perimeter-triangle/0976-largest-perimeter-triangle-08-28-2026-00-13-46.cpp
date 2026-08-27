class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;

        for(int i = n-3;i>=0;i--)
        {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a+b>c)
            {
                ans=max(ans,a+b+c);
            }
        }
        return ans;
    }
};