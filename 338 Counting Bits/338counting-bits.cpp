class Solution {
public:
 int hammingWeight(int n) {
        int ans = 0;
        while(n)
        {
            if(n  & 1)
            ans++;
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
         vector<int>  v;
        for(int i = 0;i<=n ;i++)
        {
            v.push_back(hammingWeight(i));
        }
        return v;
        
    }
};