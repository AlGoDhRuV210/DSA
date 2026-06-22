class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> v(21,0);
        for (int i = 0; i < bills.size(); i++)
        {
            int ele = bills[i];
            if(ele==5)
            v[5]++;
            else if(ele==10)
            {
                if(v[5]<=0) return false;
                v[5]--;
                v[10]++;
            }
            else
            {
                //return 15
                 if (v[5]>=1 && v[10]>=1)
                {
                    v[5]--;
                    v[10]--;
                }
                else  if(v[5]>=3 )
                {
                    v[5]-=3;
                }
                else return false;

            }
        }
        return true;
        
        
    }
};