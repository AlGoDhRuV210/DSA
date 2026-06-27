class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int ans = 1;
        sort(nums.begin(),nums.end());
        unordered_map<double, int> mpp;
        for(auto i : nums) mpp[double(i)]++;
        for (int i = 1; i < nums.size(); i++)
        {
            double ele = nums[i];
            if (ele == 1)
                continue;
            int cnt = 1;
            while (ele == floor(ele))
            {
                if (mpp[sqrt(ele)] >= 2)
                    cnt += 2;
                else
                    break;
                ele = sqrt(ele);
            }
            ans=max(ans,cnt);
        }
        ans=max(ans,mpp[1] % 2==0 ? mpp[1]-1 : mpp[1]);
        return ans;
    }
};