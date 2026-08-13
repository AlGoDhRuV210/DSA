class Solution {
public:
  
    int minEatingSpeed(vector<int>& piles, int h) {
        // int n = piles.size();
        // n piles are there 
        int m =*max_element(piles.begin(),piles.end());
       int low=1;
       int high = m;
       int ans=m;
       while(low<=high)
       {
        int mid=low+(high-low)/ 2;

     long long  a=0;
        for(auto i : piles)
        {
            a+=ceil((double)i/mid);
        }
        if(a<=(long long) h) {ans=mid,high=mid-1;}
       
        else low=mid+1;
       }
       return ans;

        
    }
};