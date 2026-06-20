class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    int ans = 0;
    int n = cardPoints.size();
    vector<int> prefix(n);
    prefix[0] = cardPoints[0];
    for (int i = 1; i < n; i++)
    {
      prefix[i] = prefix[i - 1] + cardPoints[i];
    }

    if (k == n)
      return prefix[n - 1];
    int l = 0;
    int r = n - k - 1;
    // window of n - k elements
    int total = prefix[n - 1];
    while (r < n)
    {
      ans = max(ans, total - (prefix[r] - (l > 0 ? prefix[l - 1] : 0)));
      l++;
      r++;
    }

    return ans;
  }
};