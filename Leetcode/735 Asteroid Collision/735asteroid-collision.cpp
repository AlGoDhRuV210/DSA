class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
                s.push(asteroids[i]);
            else
            {
                while (!s.empty() && s.top() > 0 && s.top() <abs(asteroids[i]))
                {
                    if (s.top() == abs(asteroids[i]))
                    {
                        s.pop();
                        break;
                    }

                    s.pop();
                }
                if (s.empty() ||  s.top()<0)
                    s.push(asteroids[i]);
                else if(s.top()==abs(asteroids[i])) s.pop();
                // else s.push(asteroids[i]);
                     
            }
        }
        
        int k = s.size();
        if(k==0) return {};
        vector<int> ans(k);
        for(int  i = k-1;i>=0;i--)
        { 
            ans[i]=s.top(); 
            s.pop();
        }
        return ans;
    }
};