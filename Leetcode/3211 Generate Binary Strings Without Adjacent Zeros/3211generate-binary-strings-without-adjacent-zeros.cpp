class Solution {
public:
vector<string> add(vector<string> v ,int n )
{
    vector<string> s;
    for(int i = 0 ; i<v.size();i++)
    {
         if(v[i][0]!='0')
        s.push_back("0"+v[i]);
    }
    for(int i = 0 ; i<v.size();i++)
    {
        s.push_back("1"+v[i]);
    }
    return s;


}
    vector<string> validStrings(int N) {
           if(N==1) return {"0","1"};
    vector<string> v =validStrings(N-1);
    return add(v,N-1);
    }
};