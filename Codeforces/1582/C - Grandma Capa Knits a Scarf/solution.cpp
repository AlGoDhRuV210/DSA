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
    string s;
    cin >> s;
    int i = 0;
    int j = n - 1;
    while (i < j && s[i] == s[j])
    {
        i++;
        j--;
    }
    if (i >= j)
    {
        cout << 0 << endl;
        return;
    }
    char c1 = s[i];
    char c2 = s[j];
    // check c1;
    int ans = INT_MAX;
    int cnt = 0;
    i = 0;
    j = n - 1;
    int flag = 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (s[i] == c1)
                i++;
            else if (s[j] == c1)
                j--;
            else
            {
                flag = 0;
                break;
            }
            cnt++;
        }
    }
    if (flag)
        ans = min(ans, cnt);
    // check c2;
    i = 0;
    j = n - 1;
    flag=1;
    cnt=0;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (s[i] == c2)
                i++;
            else if (s[j] == c2)
                j--;
            else
            {
                flag = 0;
                break;
            }
            cnt++;
        }
    }
    if (flag)
        ans = min(ans, cnt);
    if(ans==INT_MAX)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;
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