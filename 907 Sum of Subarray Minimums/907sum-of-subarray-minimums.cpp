int mod = (int)(1e9 + 7);
class Solution
{
public:
    vector<int> find_nse(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }
        return ans;
    }
    vector<int> find_psee(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();

            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        vector<int> nse = find_nse(arr);
        vector<int> pse = find_psee(arr);
        for (int i = 0; i < n; i++)
        {
            int left =  i -pse[i];
            int right = nse[i] - i;
            sum += (left * right * 1LL * arr[i]) % mod;
            sum=sum%mod;
        }
        return sum;
    }
};