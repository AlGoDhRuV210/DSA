class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m =matrix.size(),n=matrix[0].size();
        int low=0;int high=m*n -1;
        while (low<=high)
        {
            int mid=(low+high) /2;
            int row;
            
            row=mid/n;

            int col;
            
             col=mid%n;
            int ele=matrix[row][col];
            if(ele==target) return true;
            else if(ele>target) high=mid-1;
            else low=mid+1;
        }
        return false;
        
    }
};