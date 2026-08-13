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
    int mx = 0;
    int mn = 0;
    if (n % 2 == 1 || n < 4)
        cout << -1 << endl;
    else if (n == 4)
        cout << 1 << " " << 1 << endl;
    else
    {
        if (n % 4 == 0 && n % 6 == 0)
        {
            mx = n / 4;
            mn = n / 6;
        }
        else if(n % 4 == 0)
        {
            mx=n/4;
            int cnt=0;
            while(!(n%4==0 && n%6==0)){ n--;cnt++;}
            mn=n/6+cnt/4;
 
        }
        else if(n % 6 ==0)
        {
            mn=n/6; mx=1+(n-6)/4;
        }
        else {mx=1+(n-6)/4;  mn=2+(n-8)/6;}
        cout<<mn<<" "<<mx<<endl;
    }
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