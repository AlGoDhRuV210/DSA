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
    int n;
    cin >> n;
    vi a(n + 1);
    f(i, n) cin >> a[i + 1];
    map<int, int> mpp;
    for (int i = 1; i <= n; i++)
    {
        mpp[a[i]]++;
    }
    if (mpp.size() == 1)
    {
        cout << "NO
";
        return;
    }
    cout << "YES
";
    vi v;
    mpp.clear();
    for (int i = 2; i <=n; i++)
    {
        if(a[i]==a[1])
        v.push_back(i);
        else
        cout<<1<<" "<<i<<endl;
    }
    int index= -1;
    for (int i = 1; i <=n; i++)
    {
        /* code */
        if(a[i]!=a[1])
        {
            index=i;
            break;
        }
    }
    for(auto i : v)
    cout<<index<<" "<<i<<endl;
    
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