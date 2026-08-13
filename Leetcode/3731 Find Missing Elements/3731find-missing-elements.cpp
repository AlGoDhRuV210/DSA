class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool ok = true;
        if (n != nums[n - 1] - nums[0] + 1)
            ok = 0;
        set<int> s;
        for(int i = nums[0];i<=nums[n-1];i++)
        {
            s.insert(i);
        }
        s.erase(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1)
                ok = false;
            s.erase(nums[i]);
        }

        if (ok)
            return {};

        vector<int> ans(s.begin(),s.end());
        return ans;

        
    }
};