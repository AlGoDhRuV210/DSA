class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int x=0,y=0; //x odd y even
        for(auto i : nums1)
        {
            if(i&1) x++;
            else y++;
        }
        if(x==0 || y==0) return true;
        if(nums1[0] & 1) return true;
        return false;
        
    }
};