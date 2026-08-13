class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        unordered_map<char,int> mpp;
        for(auto i  : text)
        {
            mpp[i]++;
        }
    //     for(auto i : mpp)
    //    { if(i.first=='b' || i.first=='a' || i.first=='n')
    //     ans=min(ans,i.second);
    //     else if(i.first=='l' || i.first=='o')
    //     ans=min(ans,i.second/2);
    //     }
        ans=min(ans,mpp['b']);
        ans=min(ans,mpp['a']);
        ans=min(ans,mpp['n']);
        ans=min(ans,mpp['l']/2);
        ans=min(ans,mpp['o']/2);
        return ans;
    }
};