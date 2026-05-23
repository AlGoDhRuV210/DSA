class Solution {
public:
      void generate(int n , string s , int open , int close, vector<string> &v)
      {
        if(s.length()== 2*n) 
        {
            v.push_back(s);
            return;
        }
        if(open<n) {generate(n,s+"(",open+1,close,v);}
        if(close<open) {generate(n,s+")",open,close+1,v);}
        
      }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate(n,"",0,0,v);
        return v;
    }
};