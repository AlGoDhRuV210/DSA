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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    vi factors;
    for (int i = 1; i * i <= k; i++)
    {
        /* code */
        if (k % i == 0)
        {
            factors.pb(i);
            if ((k / i) != i)
                factors.pb(k / i);
        }
    }
    asort(factors);
    int ans = 0;
 
    int c = 0;
    vi fa(n + 1, 0);
    vi fb(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            c++;
            fa[c]++;
        }
        else
            c = 0;
    }
    c = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            c++;
            fb[c]++;
        }
        else
            c = 0;
    }
    vi sa(n + 1, 0), sb(m + 1, 0);
    sa[n] = fa[n];
    sb[m] = fb[m];
    for (int i = n - 1; i >= 1; i--)
    {
        sa[i] = fa[i] + sa[i + 1];
        /* code */
    }
    for (int i = m - 1; i >= 1; i--)
    {
        sb[i] = fb[i] + sb[i + 1];
        /* code */
    }
 
    for (auto i : factors)
    {
        int x = i;
        int y = k / i;
        if (x > n || y > m)
            continue;
        int p = sa[x];
        int q = sb[y];
        ans += (p * q);
    }
 
    cout << ans << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
    return 0;
}