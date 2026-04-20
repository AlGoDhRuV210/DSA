class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string ans="";
        int i =s.length()-1;
        string result="";
        while(i>=0)
        {
            //end
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            int end=i;
            while(i>=0 && s[i]!=' ') i--;
            int start = i+1;
            string word="";
            for (int j = start; j <=end; j++)
            {
                word=word+s[j];
            }
                  if(!result.empty()) result=result+" ";
            result=result + word;



        }
        return result;
    }
};
