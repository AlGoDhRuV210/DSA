class Solution {
public:
void helper(vector<int>& nums,vector<vector<int>> &v,vector<int> cur, int i)
{
    // if(i==nums.size()+1) return ;
   v.push_back(cur); 
    
    for (int j = i; j < nums.size();j++)
    {
        if(j>i && nums[j]==nums[j-1]) continue;

        cur.push_back(nums[j]);
        helper(nums,v,cur,j+1);
        cur.pop_back();
    }
    

    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        helper(nums,v,cur,0);
        return v;
    }
};