class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(auto i : nums) xr^=i;
        int bitno=0;
        int y = 0;
        while((xr & (1<<y)) == 0 ) y++;
        bitno = y;
        int zero = 0;
        int one = 0;
        for(auto i : nums)
        {
            if((( i & (1<<bitno))) == 0) 
            {
                //zero case
                zero=zero^i;
            }
            else 
            one=one^i;
        }
        return {zero,one};

    }
};