class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int cnt=0;
        if(asteroids.size()==1 && asteroids[0]>mass) return false;
        if(asteroids.size()==1 && asteroids[0]<=mass) return true;
        for(int i = 0 ;i<asteroids.size();i++)
        {
            if(asteroids[i]<=mass)
            {
                mass+=asteroids[i];
            }
            else break;
            cnt=i;
        }
        if(cnt==asteroids.size()-1) return true;
        return false;
    }
};