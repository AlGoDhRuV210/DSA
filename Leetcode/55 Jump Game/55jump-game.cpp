class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i =n-2;
        int cnt = 1;
        while(i>=0)
        {
            if(nums[i]>=cnt) cnt=1;
            else 
            cnt++;
            i--;

        }
        return cnt == 1;
    }
};