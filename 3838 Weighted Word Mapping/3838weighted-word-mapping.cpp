class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s ="";
        for(auto i : words)
        {
            int x=0;
            for(auto j : i)
            {
                x+=weights[j-'a'];
            }
            x%=26;
            s+='a'+(25-x);

        }
        return s;
        
    }
};