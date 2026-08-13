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
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        for (int j = 0; j < v[i].first; j++)
        {
            int x;
            cin >> x;
            v[i].second.push_back(x);
        }
        sort(v[i].second.begin(), v[i].second.end());
    }
    if (n == 1)
    {
        cout << *min_element(v[0].second.begin(), v[0].second.end()) << endl;
        return;
    }
    int ans = 0;
    int mn = INT_MAX;
    int index = -1;
 
    for (int i = 0; i < n; i++)
    {
        /* code */
        ans += v[i].second[1];
        if (v[i].second[1] < mn)
        {
            index = i;
            mn = v[i].second[1];
        }
    
    }
    ans-=v[index].second[1];
    int first_smallest=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(v[i].second[0]<first_smallest) 
        {
            first_smallest=v[i].second[0];
        }
    }
    ans+=first_smallest;
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