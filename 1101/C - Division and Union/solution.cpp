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
 
bool comp(pii p1, pii p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
 
    return p1.second < p2.second;
}
void solve()
{
    int n;
    cin >> n;
    vpii intervals;
    vpii question;
    // map<pii, int> mpp;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int l, r;
        cin >> l >> r;
        question.pb({l, r});
    }
    
    vpii temp = question;
    sort(all(question), comp);
 
    for (int i = 0; i < n; i++)
    {
        int l = question[i].first;
        int r = question[i].second;
        if (intervals.empty())
        {
            intervals.pb({l, r});
            continue;
        }
        int b = intervals.back().second;
        int a = intervals.back().first;
        if (l > b)
        {
            intervals.pb({l, r});
            continue;
        }
        if (l == a && r == b)
            continue;
        intervals.back().second = max(intervals.back().second, r);
    }
 
    if (intervals.size() < 2)
    {
        cout << -1 << endl;
        return;
    }
    int l = intervals[0].first;
    int r = intervals[0].second;
 
    for (auto i : temp)
    {
        if (i.second > r)
            cout << 2 << " ";
        else
            cout << 1 << " ";
    }
    cout << endl;
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