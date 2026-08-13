class Solution
{
public:
    long long subarraymin(vector<int> arr)
    {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        long long ans = 0;
        //  right as nse
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() &&  arr[s.top()] >= arr[i])
                s.pop();

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        //  left as psee
        while (!s.empty())
            s.pop();
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() &&  arr[s.top()] > arr[i])
                s.pop();

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        //find ans
        for (int i = 0; i < n; i++)
        {
            long long leftCnt = i - left[i];
            long long rightCnt = right[i] - i;
            ans += 1LL * arr[i] * leftCnt * rightCnt;
        }
        return ans;
    }
    //subarraymax
    long long subarraymax(vector<int> arr)
    {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        long long ans = 0;
        //  right as nse
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
                s.pop();

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        //  left as psee
        while (!s.empty())
            s.pop();
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] < arr[i])
                s.pop();

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            long long leftCnt = i - left[i];
            long long rightCnt = right[i] - i;
            ans += 1LL * arr[i] * leftCnt * rightCnt;
        }
        return ans;
    }


    long long subArrayRanges(vector<int> &nums)
    {
        return subarraymax(nums) - subarraymin(nums);
    }
};