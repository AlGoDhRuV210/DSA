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
    bool flag = 1;
    vi a(n);
    f(i, n)
 
    {
        cin >> a[i];
        if(i && a[i]!=a[i-1]) flag=0;
    }
    if(flag) {cout<<-1<<endl; return;}
    vi b, c;
    int mn=*min_element(a.begin(),a.end());
    for(auto i : a)
    {
        if(i==mn) b.push_back(i);
        else c.push_back(i);
    }
    cout<<b.size()<<" "<<c.size()<<endl;
    for(auto i : b) cout<<i<<" ";
    cout<<endl;
     for(auto i : c) cout<<i<<" ";
    cout<<endl;
 
    
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