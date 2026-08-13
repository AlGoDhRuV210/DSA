class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high =nums.size()-1;
        int ans=false;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
            // check if left half is sorted//..
            if(nums[low]<=nums[mid])
            {
                //yes
                if(target>=nums[low] && target<=nums[mid])
                high= mid-1;
                else low=mid+1;
            }

            else 
            //rifht hlaf is sorted
             {
                if(target>=nums[mid] && target<=nums[high])
                low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};
