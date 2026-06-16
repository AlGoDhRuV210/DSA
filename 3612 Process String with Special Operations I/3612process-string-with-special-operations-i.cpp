class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(auto i : s)
        {
            if(i>='a'   &&  i<='z')
            result=result+i;
            else if(i=='*')
            {
                if(result!="")
               result.pop_back();
            }
            else if(i=='#')
            {
                result=result+result;
            }
            else 
            reverse(result.begin(),result.end());
            
        }
        return result;
    }
};