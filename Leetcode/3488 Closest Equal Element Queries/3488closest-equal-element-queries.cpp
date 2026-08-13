class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mpp;
        int n =nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            
            mpp[nums[i]].push_back(i);
        }
        for(auto &i : mpp)
        {
            int x=i.second[0];
            i.second.insert(i.second.begin(),i.second.back()-n);
            i.second.push_back(x+n);
        }
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {

            int x=nums[queries[i]];
            if(mpp[x].size()==3) ans[i]=-1;
            else 
            {
                int pos=lower_bound(mpp[x].begin(),mpp[x].end(),queries[i])-mpp[x].begin();
            ans[i] = min(mpp[x][pos + 1] - mpp[x][pos],
                             mpp[x][pos] - mpp[x][pos - 1]);
              
               
            }



        }

        return ans;
        
    }
};