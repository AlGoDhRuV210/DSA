class Solution {
public:
void solve(int n ,vector<int>  &v,int i)
{
    if(i==n+1) return;

    // int mx = (1<<i) -1;
    // int mn = ( 1<<(i-1) );
    // if(i==1) mn=0;
    // for(int i =0;i<)
    if(i==1)
    { 
        v.push_back(0);
        v.push_back(1);
    }
    else 
    {
        int add= (1<<(i-1));
        for(int j = v.size()-1; j>=0;j--)
        {
            v.push_back(v[j]+add);
        }         

    }
     solve(n,v,i+1);


}
    vector<int> grayCode(int n) {
        vector<int>  v;
        solve(n,v,1);
        return v;
    }
};