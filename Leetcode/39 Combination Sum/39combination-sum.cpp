class Solution {
public:
   void helper(vector<int>& candidates, int target,vector<vector<int>> &v,int i , int sum , vector<int> cur)
   {
    if(sum>target) {return;}
    if(sum==target) {v.push_back(cur); return;}
    if(i==candidates.size()) { return;}
    // take
    cur.push_back(candidates[i]);
    helper(candidates,target,v,i,sum+candidates[i],cur);
    // exclude
    cur.pop_back();
    helper(candidates,target,v,i+1,sum,cur);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v ;
        vector<int> cur;
        helper(candidates,target,v,0,0,cur);
        return v ;
        
    }
};