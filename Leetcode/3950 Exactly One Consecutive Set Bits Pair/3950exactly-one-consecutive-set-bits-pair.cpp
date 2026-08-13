class Solution {
public:
    int cnt=1;
    
    bool consecutiveSetBits(int n) {
        int temp=n;
        string s = "";
        while(temp>=1)
            {
                if(temp%2==1) s+="1";
                else s+="0";
                temp/=2;

            }
        reverse(s.begin(),s.end());
        int pair=0;
        for(int i =s.length()-1;i>=0;i--)
            {
                if(s[i]=='1')
                   {
                       if(i>0 && s[i-1]=='1') {pair++; }
                       
                   }
            }
        if(pair==1) return true;
        else return false;
        

        
    }
};