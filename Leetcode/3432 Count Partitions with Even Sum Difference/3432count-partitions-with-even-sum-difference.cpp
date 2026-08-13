class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt=0;
        int n =nums.size();
        for(auto i : nums) {if(i%2==1) cnt++;}
        if(cnt%2==0) return n-1;
        return 0;
    }
};