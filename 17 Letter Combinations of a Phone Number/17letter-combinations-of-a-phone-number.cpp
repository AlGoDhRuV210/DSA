class Solution
{
public:
void helper(vector<vector<char>> v,vector<int> a, vector<string>  &ans,int i ,string cur)
{

    // a has string
    if(i==a.size()) {ans.push_back(cur); return;}
    for (int j = 0; j < v[a[i]].size(); j++)
    {
        string s = cur;
        s+=v[a[i]][j];
        helper(v,a,ans,i+1,s);
    }
    


}
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> v = {{},
                                  {},
                                  {'a', 'b', 'c'},
                                  {'d', 'e', 'f'},
                                  {'g', 'h', 'i'},
                                  {'j', 'k', 'l'},
                                  {'m', 'n', 'o'},
                                  {'p', 'q', 'r', 's'},
                                  {'t', 'u', 'v'},
                                  {'w', 'x', 'y', 'z'}};
        vector<int> a;
        for (auto i : digits) a.push_back(i-'0');
        vector<string>  ans;
        helper(v,a,ans,0,"");
        return ans;

    }
};