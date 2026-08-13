#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <limits>
#include <functional>
#include <bitset>
#include <tuple>
#include <complex>
#include <math.h>
#define f(i, n) for (int i = 0; i < n; i++)
#define vi vector<long long>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define mci map<char, int>
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sort(x) sort(x.begin(), x.end())
#define int long long
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
   int n, c;
   cin >> n >> c;
 
   vi a(n), b(n);
   f(i, n) cin >> a[i];
   f(i, n) cin >> b[i];
   int ans = 0;
   // without rearrge
   for (int i = 0; i < n; i++)
   {
      if (a[i] < b[i])
      {
         ans = -2;
         break;
      }
      else
         ans += a[i] - b[i];
   }
   // rearrgae
   sort(a);
   sort(b);
   int temp = 0;
   temp += c;
   for (int i = 0; i < n; i++)
   {
      if (a[i] < b[i])
      {
         temp = -2;
         break;
      }
      temp += a[i] - b[i];
   }
   if (ans != -2 && temp != -2)
      ans = min(ans, temp);
   else if (ans == -2 && temp != -2)
      ans = temp;
   else
      ans = -1;
 
   cout << ans << endl;
}
 
int32_t main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
 
   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }
   return 0;
}