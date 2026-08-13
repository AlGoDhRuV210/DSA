class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        map<pair<int, int>, int> mpp;

        mpp[{0, nums[0]}] = 1;
        mpp[{0, -nums[0]}] = 1;
        if(nums[0]==0)
        mpp[{0, nums[0]}] = 2;


        for (int i = 1; i < n; i++) {
            /* code */
            for (int cur = -sum; cur <= sum; cur++) {
                int takeplus = mpp[{i - 1, cur - nums[i]}];
                int takeminus = mpp[{i - 1, cur + nums[i]}];

                mpp[{i, cur}] = takeplus + takeminus;
            }
        }

        return mpp[{n - 1, target}] ;
    }
};