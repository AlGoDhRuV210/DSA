class Solution {
public:
    bool judgeCircle(string moves) {
        int rcnt=0;
        int ucnt=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i] == 'U') ucnt++;
            else if(moves[i] == 'D') ucnt--;
            else if(moves[i] =='R') rcnt++;
            else if(moves[i] == 'L') rcnt--;
        }
        if(!rcnt && ! ucnt) return true;
        else return false;

    }
};