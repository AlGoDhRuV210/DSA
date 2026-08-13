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
#define rev(x) reverse(all(x))
#define asort(x) sort(all(x))
#define dsort(x) sort(all(x), greater<>())
#define int long long
#define double long double
#define endl '
'
 
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
class DisjointSet
{
private:
    vector<int> parent, rank, size;
 
public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
 
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
 
    void unionByRank(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
 
    void unionBySize(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    int zeros = n / 2;
    int one = n - (n / 2);
    int mx = zeros + one - 2;
    if (mx < k)
    {
        cout << -1 << endl;
        return;
    }
    string ans = "";
    if (k == 0)
    {
        if (n == 2)
        {
            cout << "01" << endl;
            return;
        }
        while (zeros--)
        {
            ans += "01";
            one--;
        }
        if(one)
        ans = "1" + ans;
        cout << ans << endl;
        return;
    }
    if (n == 3)
    {
        if (k == 0)
            cout << "101" << endl;
        else if (k == 1)
            cout << "100" << endl;
 
        return;
    }
    if (n == 2)
    {
        if (k == 0)
            cout << "10" << endl;
        else
            cout << -1 << endl;
        return;
    }
    int byzero = k / 2;
    int byone = k - k / 2;
    if (byzero > 0)
    {
        for (int i = 0; i < byzero + 1; i++)
        {
            ans += "0";
        }
    }
    else
    {
 
        ans = "0110";
        zeros -= 2;
        one -= 2;
        while (zeros--)
        {
            ans = "01" + ans;
            one--;
        }
        if (one)
            ans = "1" + ans;
        cout << ans << endl;
        return;
    }
    if (byone > 0)
    {
        for (int i = 0; i < byone + 1; i++)
        {
            ans += "1";
        }
    }
    zeros -= (byzero + 1);
    one -= (byone + 1);
    // int rem = zeros + one;
    // if (rem % 2 == 1)
    // {
    //     cout << "1" + ans << endl;
    //     return;
    // }
    for (int i = 0; i < min(zeros, one); i++)
    {
        ans = "01" + ans;
    }
    int m = min(zeros, one);
    zeros -= m;
    one -= m;
 
    if (one)
        ans = "1" + ans;
    if (zeros)
        ans = ans + "0";
    cout << ans << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}