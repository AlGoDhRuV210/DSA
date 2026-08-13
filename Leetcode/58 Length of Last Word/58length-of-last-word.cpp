class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        if(s.length() ==1 && s[0]!=' ') return 1;
        while(end>0 && s[end]==' ' ) end--;
        if(end==0 && s[end]==' ' ) return 0;
        
        int start=end;
        while(start>=0 && s[start] != ' ') start--;
        return end-start ;
    }
};