class Solution {
public:
      int findrowno(int col,vector<vector<int>>& mat)
      {
        int mx=-1;
        int ind=-1;
         for(int i =0;i<mat.size();i++)
         {
            if(mat[i][col]>mx) {mx=mat[i][col]; ind=i;}
         }
         return ind;
      }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n =mat.size();int m =mat[0].size();    
        int low=0;
            int high=m-1;
            while (low<=high)
            {
                int mid=(low+high)/2;
                int rowno=findrowno(mid,mat);
                int left = mid-1>=0 ? mat[rowno][mid-1] : -1;
                int right = mid+1<m ? mat[rowno][mid+1] : -1;
                if(mat[rowno][mid]> left && mat[rowno][mid]> right )
                return {rowno,mid};
                else if(mat[rowno][mid]<left )  high=mid-1;
                else low=mid+1; 
            }
            return {-1,-1};
            
     }
};