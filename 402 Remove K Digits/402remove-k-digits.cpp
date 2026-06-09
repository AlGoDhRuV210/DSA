class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
    
        int n = num.size();
        if(k==n) return "0";
       for(int i = 0 ;i<n;i++)
       {
        while(!s.empty() && k>0 && s.top()>num[i])
              {  s.pop();
                      k--;
               }
          s.push(num[i]);
        }
            string ans ="";
        if(k==0)
        {
           while(!s.empty())
{
    ans.push_back(s.top());
    s.pop();
}

reverse(ans.begin(), ans.end());
          
        }
        else 
        {
            while(k--)
            s.pop();
           while(!s.empty())
{
    ans.push_back(s.top());
    s.pop();
}

reverse(ans.begin(), ans.end());

        }
        int z = ans.length();
        int j =0;
        while(j<z  &&  ans[j]=='0') j++;
        if(j==z) return "0";
        return ans.substr(j,z-j);
        
    }
};