class Solution {
public:

void helper(vector<int>& candidates, int target,vector<vector<int>> &v,int i , int sum , vector<int> cur)
{
    if(sum==target) 
    {
        sort(cur.begin(),cur.end()); 
        v.push_back(cur);
         return;
    }
    // take
   for(int j = i;j<candidates.size();j++)
  { if(j>i && candidates[j]==candidates[j-1] ) continue;
  // include 
  if(sum>target) break;
    cur.push_back(candidates[j]);
    helper(candidates,target,v,j+1,sum+candidates[j],cur);
    // exclude
    cur.pop_back();
   }


 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> v ;
         sort(candidates.begin(),candidates.end());
         
        vector<int> cur;
        helper(candidates,target,v,0,0,cur);
        return v ;
        
    }
};