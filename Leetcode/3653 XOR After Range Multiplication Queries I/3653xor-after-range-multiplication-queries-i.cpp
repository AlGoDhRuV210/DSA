class Solution {
public:
const long long MOD = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto i : queries)
        {
            int l =i[0];
            int r =i[1];
            int j =l;
            while(j<=r)
            {
                long long temp=((long long )nums[j]*i[3] ) % (MOD);
                nums[j]= (int)temp;
                j+=i[2];
            }
        }
        int ans=0;
        for(auto i : nums)
        {
            ans=ans^i;
        }
        return ans;
    }
};