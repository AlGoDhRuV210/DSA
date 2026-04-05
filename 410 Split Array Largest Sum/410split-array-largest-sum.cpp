class Solution {
public:
bool check(vector<int> nums, int k,int sum)
{
    int parts=1;
    int cur=0;
    for(int i : nums)
    {
        if(i+cur>sum) {parts++;cur=i;}
        else cur+=i;
    }
    if(parts>k) return false;
    else return true;

}
    int splitArray(vector<int>& nums, int k) {
        // if(k==nums.size()) return *max_element(nums.begin(),nums.end());
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans =0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums,k,mid))
             {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            
        }
        return ans;
    }
};