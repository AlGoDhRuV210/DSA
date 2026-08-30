class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i1 = min_element(nums.begin(),nums.end())-nums.begin();
        int i2 = max_element(nums.begin(),nums.end())-nums.begin();
        if(i1>i2)
        swap(i1,i2);
        int ans= n;
        ans=min(ans,i2+1);
        ans=min(ans,n-i1);
        if(i1!=i2)
        ans=min(ans,i1+1+n-i2);



            return ans;
            
    }
};