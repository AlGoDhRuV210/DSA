class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;
        for (int i = 0; i <  landStartTime.size(); i++)
        {
            int time=landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); j++)
            {
                if(time>=waterStartTime[j]) 
                {
                    time+=waterDuration[j];
                }
                else
                {
                    time=waterStartTime[j] +waterDuration[j];
                }
            ans=min(ans,time);
            time=landStartTime[i] + landDuration[i];
            }
            
        }
        for (int i = 0; i <  waterStartTime.size(); i++)
        {
            int time=waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < landStartTime.size(); j++)
            {
                if(time>=landStartTime[j]) 
                {
                    time+=landDuration[j];
                }
                else
                {
                    time=landStartTime[j] +landDuration[j];
                }
            ans=min(ans,time);
            time=waterStartTime[i] + waterDuration[i];

            }
            
        }
        return ans;

        
    }
};