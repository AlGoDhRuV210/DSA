class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> ans;
         int low=0;
        int high =nums.size()-1;
          int s=-1;
          int e=-1;
         //  fidn starting
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
          { s=mid ; high=mid-1;}
           
            else if (nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        //find end
        low=0;high =nums.size()-1;
         while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
          { e=mid ; low=mid+1;}
           
            else if (nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
           return {s,e};

        
    }
};