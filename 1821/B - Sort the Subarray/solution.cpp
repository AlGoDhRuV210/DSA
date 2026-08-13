#define _USE_MATH_DEFINES
#include <iostream>
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
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define f2(i, a, b, c) for (int i = a; i <= b; i += c)
#define vi vector<long long>
#define vs vector<string>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sort(x) sort(x.begin(), x.end())
#define int long long
 
#define Its ios::sync_with_stdio(false);
#define Dhruv cin.tie(nullptr);
#define here cout.tie(nullptr);
 
using namespace std;
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    vi b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
 
    // a is orginal and b is after sorting a from [l,r]..
    int l=1;
    int r=1;
    int left=-1;
    int right=n+1;
    for (int i = 1; i <=n; i++)
    {
        if(a[i]!=b[i])
        {
            left=i;
            break;
        }
    }
    for (int i =n; i>0; i--)
    {
        if(a[i]!=b[i])
        {
            right=i;
            break;
        }
    }
    while(left>1 && b[left-1]<=b[left] )
    left--;
    while(right<n && b[right]<=b[right+1] )
    right++;
 
   if(left!=-1)
   {
    l=left;
    r=right;
   }
 
    
 
    
    cout << l << " " << r << endl;
}
 
int32_t main()
{
    Its Dhruv here int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}