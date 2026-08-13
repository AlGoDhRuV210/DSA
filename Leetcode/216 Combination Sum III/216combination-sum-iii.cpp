class Solution {
public:
  void helper(int k, int n,vector<vector<int>> &v ,  vector<int> cur,int i,int sum )
  {
    if(i>9) 
     {
          if(sum==n && cur.size()==k) v.push_back(cur);
           return ;
    }
    if(sum>n) return ;
    // if(cur.size()==k) 
    // {
    //       if(sum==n) v.push_back(cur);
    //        return ;
    // }
        cur.push_back(i);
        helper(k,n,v,cur,i+1,sum+i);
        cur.pop_back();
        helper(k,n,v,cur,i+1,sum);

 }





  
    vector<vector<int>> combinationSum3(int k, int n) {
        // sum = k
        vector<vector<int>> v;
        vector<int> cur;
        int sum = 0;
        helper(k,n,v,cur,1,sum);
        return v;

    }
};