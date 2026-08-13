class Solution
{
public:
  int countValidSubarrays(vector<int> &nums, int x)
  {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      long long sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += nums[j];
          if(sum<=9 && sum==x) {ans++; continue;}
          if(sum<=9 && sum!=x) { continue;}
          
        int lastdigit = sum % 10;
        long long temp = sum;
        int firstdigit = lastdigit;
        while (temp >0)
        {
          firstdigit=temp%10;
          temp /= 10;
        }
        if (firstdigit == x && lastdigit == x)
          ans++;
      }
    }
    return ans;
  }
};