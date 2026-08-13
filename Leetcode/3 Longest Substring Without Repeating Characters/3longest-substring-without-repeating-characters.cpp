class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(s=="") return 0;
        unordered_map<char,int> mpp; // int is index
        int l =0,r=1;
        int maxlen = 1;
        mpp[s[0]]=0;
        while(r<n)
        {
            if(mpp.find(s[r])==mpp.end() || mpp[s[r]]<l)
            {
                maxlen=max(maxlen,r-l+1);
            }
            else
            {
               l=mpp[s[r]]+1;  
            }
            mpp[s[r]]=r;
                r++;
        }

        return maxlen;
        
    }
};