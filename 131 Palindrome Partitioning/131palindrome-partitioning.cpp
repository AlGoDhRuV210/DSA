class Solution {
public:
bool is_palindrome(string s , int start, int end)
{
    while(start<end)
    {
        if(s[start]!=s[end]) return false;
        else {start++; end--;}
    }
    return true;

}
void helper(string s ,  vector<vector<string>> &v,vector<string> cur,int index)
{
    if(index==s.size()) {v.push_back(cur); return;}

    for (int i = index; i < s.length(); i++)
    {
        if(is_palindrome(s,index,i))
        {
            cur.push_back(s.substr(index,i-index+1));
            helper(s,v,cur,i+1);
            cur.pop_back();
        }
    }
    
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> cur={};
        helper(s,v,cur,0);
        return v;

    }
};