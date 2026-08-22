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
int cnt;
vi vis;
 
void dfs(int i, vector<vi> &adj)
{
    cnt++;
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(j, adj);
        }
    }
}
void solve()
{
    cnt = 0;
    int n, k;
    cin >> n >> k;
    vector<vi> adj(n + 1);
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if (c == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
            flag = 1;
    }
    if (!flag)
    {
        cout << 0 << endl;
        return;
    }
    vis.clear();
    vis.assign(n + 1, 0);
    int final = 0;
 
    for (int i = 1; i <= n; i++)
    {
        /* code */
        if (!vis[i])
        {
            cnt = 0;
            dfs(i, adj);
            int cntpowerk = cnt;
            for (int i = 0; i < k - 1; i++)
            {
                /* code */
                cntpowerk *= cnt % MOD1;
                cntpowerk %= MOD1;
            }
            final += cntpowerk - cnt;
        }
    }
 
    int total = n;
    for (int i = 0; i < k - 1; i++)
    {
        /* code */
        total *= n % MOD1;
        total %= MOD1;
    }
    int ans = total - final - n;
    while (ans < 0)
        ans += MOD1;
    cout << (ans) % MOD1 << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
    return 0;
}