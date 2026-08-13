class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int ans = 1;
        int n = ratings.size();
        int peak = -1;
        int down = 0;
        int last =1;
        int i = 1;
       while(i<n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                ans += 1;
                last = 1;
                down = 0;
                i++;
            }
            else if (ratings[i] > ratings[i - 1])
            {
                ans += last + 1;
                last++;
                down = 0;
                i++;
            }
            else
            {
                down=0;
                peak=last;
                while (i < n && ratings[i] < ratings[i - 1])
                {
                    down++;
                    ans+=down;
                    i++;
                }
                if(down>=peak)
                ans+=down-peak+1;
                last=1;
            }
        }
        return ans;
    }
};