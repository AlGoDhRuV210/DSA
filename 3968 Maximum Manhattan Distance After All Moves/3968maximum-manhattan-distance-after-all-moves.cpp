class Solution {
public:
    int maxDistance(string moves) {
        int x = 0,y=0;
        int space=0;
        for(auto i : moves)
        {
            if(i=='U') y++;
            else if(i=='D') y--;
            else if(i=='R') x++;
            else if(i=='L') x--;
            else space++;
            
        }
        if(x>y) swap(x,y);
        if(y>0) y+=space;
        else y-=space;
    return abs(x)+abs(y);
    }
};