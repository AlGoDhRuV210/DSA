class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;

        int n =words.size();
        for(int i =0;i<n;i++)
        {
            if(words[i]==target) {
                int dif=abs(i-startIndex);
                ans=min(ans,dif);
            ans=min(ans,n-(dif));}
        }
        if(ans!=INT_MAX) return ans;
        else return -1;
        
    }
};