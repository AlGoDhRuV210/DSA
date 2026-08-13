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
    int n;
    cin >> n;
    vi a(n), b(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];
    unordered_map<int, int> mpp;
    int c = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == c)
            cnt++;
        else
        {
            if (mpp.find(c) == mpp.end())
            {
                mpp[c] = cnt;
                cnt = 1;
                c = a[i];
            }
            else
            {
                mpp[c] = max(mpp[c], cnt);
                cnt = 1;
                c = a[i];
            }
        }
    }
    if (mpp.find(c) == mpp.end())
    {
        mpp[c] = cnt;
        cnt = 1;
    }
    else
    {
        mpp[c] = max(mpp[c], cnt);
        cnt = 1;
    }
    int ans = 1;
for (auto x : mpp)
{
    ans = max(ans, x.second);
}
    // check b[i]
    c = b[0];
    cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] == c)
            cnt++;
        else
        {
            if (mpp.find(c) == mpp.end())
            {
                ans = max(ans, cnt);
                cnt = 1;
                c = b[i];
            }
            else
            {
                ans = max(ans, mpp[c] + cnt);
                cnt = 1;
                c = b[i];
            }
        }
    }
    if (mpp.find(c) == mpp.end())
    {
        ans = max(ans, cnt);
    }
    else
    {
        ans = max(ans, mpp[c] + cnt);
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