class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while(n>0)
        {
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());
        int s = v.size();
        return v[s-1]*v[s-2];
    }
};