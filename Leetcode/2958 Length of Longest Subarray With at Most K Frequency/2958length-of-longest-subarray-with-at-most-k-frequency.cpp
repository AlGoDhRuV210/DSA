class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int mxlen = 0;
        int j = 0;
        for(int i = 0;i<n;i++)
        {
            int ele = nums[i];
            mpp[ele]++;
            if(mpp[ele]<=k)
            {
                mxlen=max(i-j+1,mxlen);
            }
            else 
            {
                while(mpp[ele]>k)
                {
                    mpp[nums[j]]--;
                    j++;
                }
            }
        }
        return mxlen;
    }
};