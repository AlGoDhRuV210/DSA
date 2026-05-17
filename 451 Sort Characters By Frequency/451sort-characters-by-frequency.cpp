class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> v;
        sort(s.begin(),s.end());
        int cnt=0;
        char c=s[0];
        for(int i =0;i<s.length();i++)
        { 
             c=s[i];
           while(i<s.length() && s[i]==c )
           {
             cnt++;
             i++;
           }
           v.push_back({cnt,c});
           i--;
           cnt=0;
        }
         sort(v.begin(),v.end());
         string result="";
         for(auto i : v)
         result+=string(i.first,i.second);
         reverse(result.begin(),result.end());
         return result;

    }
};