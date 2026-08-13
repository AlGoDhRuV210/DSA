class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int cnt=0;
        for(int i =0;i<nums.size();i++)
        {
            presum+=nums[i];
            int rem=presum-k;

            if(mpp.find(rem)!=mpp.end())
            cnt+=mpp[rem];

            mpp[presum]++;
        }
         return cnt;
    }
};