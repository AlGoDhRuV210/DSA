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
    vi a(n);
    vpii v(n); // {value , index}
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[i] = {a[i], i};
    }
    sort(a);
    vi presum(n);
    presum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        presum[i] = presum[i - 1] + a[i];
    }
    sort(v);
    vi ans(n);
    ans[v[n - 1].second] = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans[v[i].second] = i;
        // compare presum[i] with v[i+1].first
        int k = i;
 
        while(k<n)
        {
            pair<int,int> temp= {presum[k]+1,INT_MIN};
            int index= lower_bound(v.begin(),v.end(),temp) - v.begin();
            index--;
            if(index==k)
            break;
            ans[v[i].second]+=index-k;
            k=index;
        }
         
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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