class Solution {
public:
     int BS(vector<vector<int>>& mat,int i )
     {
        sort(mat[i].begin(),mat[i].end());
        int ans=0;
        int n = mat[0].size();
       int low=0; int high=n-1;
       while(low<=high)
       {

        int mid=(low+high)/2;
        if(mat[i][mid]==1)
        {
            ans=n-mid;
            high=mid-1;
        }
        else low=mid+1;
       }
       return ans;

     }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt=INT_MIN;
        int index=-1;
        for(int i = 0;i<m;i++)
        {
            int c=BS(mat,i);
            if(c>cnt) {cnt=c;index=i;}
        }

        return {index,cnt};
       
    }
};
