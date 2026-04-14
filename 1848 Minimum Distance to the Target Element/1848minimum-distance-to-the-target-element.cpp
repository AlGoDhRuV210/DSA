class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INT_MAX;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==target) 
            {
                int abs=start-i;
                if(abs<0) abs=abs*(-1);
                ans=min(ans,abs);
            }

        }
        return ans;
    }
};