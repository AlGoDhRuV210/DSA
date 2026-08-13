class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string ans="";
        int cnt=0;
        for(auto i : s)
        {
            if(i=='(')
            {
                if(cnt>0) ans+=i;
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt>0) ans+=i;
            }

        }
        return ans;
        
        

    }
};