
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int flag=1;
        int i =0;
        string result="";
        if(strs.size()==1 && strs[0]=="") return result;
        int mn=INT_MAX;
        for(int j=0;j<strs.size();j++)
        {
            mn=min(mn,(int)strs[j].length());
        }
        while(i<mn)
        {
            for(int j =0;j<strs.size()-1 ;j++)
            {
                if(strs[j]=="" || strs[j+1]=="") return "";
                if(strs[j][i]!=strs[j+1][i])
                return result;
            }

            result=result+strs[0][i];
            i++;

        }
        return result;
    }
};