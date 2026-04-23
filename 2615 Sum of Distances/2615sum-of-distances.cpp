class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n =nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }
        vector<long long> res(n,0);
       for(auto i : m)
       {
        auto v = i.second; //vector wiith frequencies
        long long S=accumulate(v.begin(),v.end(),0LL);
        long long prefix=0;
        for (int j = 0; j < v.size(); j++)
        {
            prefix+=v[j];
            res[v[j]]=v[j]*(2*j-(v.size()-1)+1) - 2*prefix + S;
        }
        

       }

        return res;
        

    }
};