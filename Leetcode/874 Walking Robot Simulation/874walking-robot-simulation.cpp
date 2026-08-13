class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        string dir="+y";
       pair<int,int> cur={0,0};
       int max_dis=0;
       set< pair<int,int>> s;
       for(auto  i : obstacles)
       {
        s.insert({i[0],i[1]});
       }
        for(auto i : commands)
        {

            if(i==-2) 
            {
               if(dir=="+y") dir="-x";
               else if(dir=="-x") dir="-y";
               else if(dir=="-y") dir="+x";
               else if(dir=="+x") dir="+y";
            }
            else if(i==-1) 
            {
               if(dir=="+y") dir="+x";
               else if(dir=="-x") dir="+y";
               else if(dir=="-y") dir="-x";
               else if(dir=="+x") dir="-y";
            }
            else 
            {
                 if(dir=="+y") 
                 {
                    while(i>0)
                    {
                        if(s.find({cur.first,cur.second+1}) == s.end()) {cur.second++;i--;}
                        else break;
                    }
                    max_dis=max(max_dis,(cur.first*cur.first + cur.second*cur.second));
                 }
                 else if(dir=="-y") 
                 {
                    while(i>0)
                    {
                        if(s.find({cur.first,cur.second-1}) == s.end()) {cur.second--;i--;}
                        else break;
                    }
                    max_dis=max(max_dis,(cur.first*cur.first + cur.second*cur.second));
                 }
                 else if(dir=="+x") 
                 {
                    while(i>0)
                    {
                        if(s.find({cur.first+1,cur.second}) == s.end()) {cur.first++;i--;}
                        else break;
                    }
                    max_dis=max(max_dis,(cur.first*cur.first + cur.second*cur.second));
                 }
                 else 
                 {
                    while(i>0)
                    {
                        if(s.find({cur.first-1,cur.second}) == s.end()) {cur.first--;i--;}
                        else break;
                    }
                    max_dis=max(max_dis,(cur.first*cur.first + cur.second*cur.second));
                 }
              
                
            }

           
        }
        return max_dis;
    }
};