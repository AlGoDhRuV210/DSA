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
    f(i, n) cin >> a[i];
    if (n < 3)
    {
        cout << "YES" << endl;
        return;
    }
    int i = 0;
    int j = n - 1;
    bool ans = true;
    int ele1 = -1, ele2 = -1;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else
        {
            ele1=a[i];
            ele2=a[j];
            break;
        }
    }
    // check ele1
    i=0;
    j=n-1;
    while(i<j)
    {
     if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if(a[i]==ele1)
        {
            i++;
        }   
        else if(a[j]==ele1)
        {
            j--;
        }
        else break;
    }
    if(i>=j)
    {
        cout<<"YES"<<endl;
        return;
    }
    i=0;
    j=n-1;
    while(i<j)
    {
     if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if(a[i]==ele2)
        {
            i++;
        }   
        else if(a[j]==ele2)
        {
            j--;
        }
        else break;
    }
    if(i>=j)
    {
        cout<<"YES"<<endl;
        return;
    }
 
    cout<<"NO"<<endl;
 
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