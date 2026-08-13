class Solution {
public:
    int reverseBits(int n) {
        string s = "";
        int i = 0;
        int k =32;
        while(k--)
        {
            if(n&(1<<i))s+="1";
            else s+="0";

            i++;
        }
        int ans=0;
        int p=0;
        for(int j = s.length()-1; j>=0; j--)
        {
            if(s[j]=='1') 
            {
                ans+=(1<<p);
            }
            p++;
        }
        return ans;
        
    }
};