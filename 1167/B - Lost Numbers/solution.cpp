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
 
int32_t main()
{
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    v = {4, 8, 15, 16, 23, 42};
 
    unordered_map<int, pair<int, int>> mpp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            mpp[v[i] * v[j]] = {v[i], v[j]};
        }
    }
 
    vector<int> ans(6);
    int x, y;
    cout << "? 1 2" << endl;
    cout.flush();
    cin >> x;
    cout << "? 2 3" << endl;
    cout.flush();
    cin >> y;
    for (int j = 0; j < 1; j++)
    {
        int a = mpp[x].first;
        int b = mpp[x].second;
        int c = mpp[y].first;
        int d = mpp[y].second;
        if (a == c || c == b)
            ans[1] = c;
        else
            ans[1] = d;
 
        ans[2] = y / ans[1];
        ans[0] = x / ans[1];
    }
 
    cout << "? 4 5" << endl;
    cout.flush();
    cin >> x;
    cout << "? 5 6" << endl;
    cout.flush();
    cin >> y;
    int a = mpp[x].first;
    int b = mpp[x].second;
    int c = mpp[y].first;
    int d = mpp[y].second;
    if (a == c || c == b)
        ans[4] = c;
    else
        ans[4] = d;
 
    ans[5] = y / ans[4];
    ans[3] = x / ans[4];
    cout << "! ";
    for (auto i : ans)
        cout << i << " ";
 
    cout << endl;
 
    return 0;
}