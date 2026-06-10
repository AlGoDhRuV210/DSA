class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int n = heights.size();
        int ans=0;
        for(int i = 0 ;i<n;i++)
        {
             
                while(!s.empty() && heights[s.top()]>heights[i])
                {
                    int ele = s.top();
                    s.pop();
                    int height=heights[ele];
                    int pse= (!s.empty()) ? s.top() : -1;
                    int width=(i-pse-1);
                    ans=max(ans,width * height);
                }
                s.push(i);
            
        }
        
        return ans;
        
    }
};