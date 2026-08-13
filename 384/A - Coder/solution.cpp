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
    int temp = n;
    int cnt = 0;
    string s1 = "";
    // odd wali
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s1 += ".";
        else
            s1 += "C";
    }
    string s2 = "";
    // even wali
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s2 += "C";
        else
            s2 += ".";
    }
   cout<<(n/2)*(n/2) + ((n+1)/2)*((n+1)/2)<<endl;
    while (n--)
    {
        if (cnt % 2 == 0)
        {
            {for(auto i : s2) cout<<i;
            cout<<endl;}
        }
        else
            {for(auto i : s1) cout<<i;
            cout<<endl;}
            cnt++;
    }
}
 
int32_t main()
{
    Its Dhruv here int t;
     
        solve();
    
    return 0;
}