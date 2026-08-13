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
#define vpii vector<PII>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define asort(x) sort(all(x))
#define int long long
 
#define Its ios::sync_with_stdio(false);
#define Dhruv cin.tie(nullptr);
#define here cout.tie(nullptr);
 
using namespace std;
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
    int n, p;
    cin >> n >> p;
    vi a(n), b(n), c(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];
    multimap<int, int> s;
    multimap<int, int> s1;
    multimap<int, int> s2;
    multimap<int, int> s3;
    multimap<int, int> s4;
    multimap<int, int> s5;
    multimap<int, int> s6;
    multimap<int, int> s7;
    multimap<int, int> s8;
    multimap<int, int> s9;
 
    for (int i = 0; i < n; i++)
    {
        s.insert({b[i], i}); /* code */
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        auto it = s.find(b[i]);
 
        c[i] = a[it->second];
 
        s.erase(it);
    }
    s1=s;
    s2=s;
    s3=s;
    s4=s;
    s5=s;
    s6=s;
    s7=s;
    s8=s;
    s9=s;
    a = c;
    int ans = 0;
    ans += p;
    int rem = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (rem <= 0)
            break;
        if (p > b[i])
        {
            int x = min(rem, a[i]);
            ans += b[i] * x;
            rem -= x;
        }
        else
          {  ans += p; 
            rem-=1;}
    }
    cout<<ans<<endl;
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