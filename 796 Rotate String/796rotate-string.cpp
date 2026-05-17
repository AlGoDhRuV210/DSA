class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.length()!=goal.length()) return false;
       int n = s.length();
       string m = s+s;
       for(int i =0;i<n;i++)
       {
        if(m.substr(i,n)==goal) return true;
       }
       return false;
    }
};