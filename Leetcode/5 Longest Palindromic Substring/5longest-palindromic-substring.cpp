class Solution {
public:
   bool ispalindrome(const string &s , int i , int j)
   {
     while(i<j) 
     {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
     }
     return true;
   }
    string longestPalindrome(string s) {
        int maxlen=1;
        int start=0;int end=0;
        int n =s.length();

        for(int i =0;i<n;i++)
        {
            for(int j =i+maxlen;j<n;j++)
         {
            if(ispalindrome(s,i,j)) 
            {
                if(j-i+1 > maxlen)
                {
                    maxlen=j-i+1;
                    start=i;end=j;
                }

            }
         }
        }

        return s.substr(start,maxlen);
        
        
    }
};