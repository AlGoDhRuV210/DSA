class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int cnt = 0;
        while(i<n && cnt<k)
        {
            if(nums[i]<0)
            {
                nums[i]=-nums[i];
                cnt++;
            i++;
            }
            else
            break;
        }
        if((k-cnt)%2==0)
        return accumulate(nums.begin(),nums.end(),0LL);

        int x =  accumulate(nums.begin(),nums.end(),0LL);;
        int y = *min_element(nums.begin(),nums.end());
        return x - 2*y;
    }
};