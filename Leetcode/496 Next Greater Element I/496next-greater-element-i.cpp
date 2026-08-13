class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mpp;
        vector<int> res;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();

            if(s.empty()) mpp[nums2[i]]=-1;
            else mpp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        for(auto i : nums1)
        res.push_back(mpp[i]);
        return res;
    }
};