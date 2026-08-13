class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN; int ele2=INT_MIN;

        int n = (nums.size()/3);
        for(auto i : nums)
        {
         if(cnt1==0  && i!=ele2) {ele1=i; cnt1++;}
            else if(cnt2==0  && i!=ele1) {ele2=i ; cnt2++;}
            else if(i==ele1) cnt1++;
            else if(i==ele2) cnt2++;
            else {cnt2--; cnt1--;}


        }
        //check
        vector<int> result;
        int c1=0; int c2=0;
        for(auto i : nums)
        {
            if(i==ele1) c1++;
            if(i==ele2) c2++;
        }
        
        
        if(c1>n) result.push_back(ele1);
        if(c2>n) result.push_back(ele2);
        return result;

    }
};