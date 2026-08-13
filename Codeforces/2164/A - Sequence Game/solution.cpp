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
#define VPII vector<PII>
#define MII map<int, int>
#define SI set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define asort(x) sort(all(x))
#define int long long
#define double long double
 
using namespace std;
 
#define int long long
#define double long double
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
typedef complex<int> P;
#define X real()
#define Y imag()
 
class DisjointSet
{
    vector<int> rank, parent, size;
 
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else
            parent[v] = u, rank[u]++;
    }
    void unionBySize(int u, int v)
    {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;
        if (size[u] < size[v])
            parent[u] = v, size[v] += size[u];
        else
            parent[v] = u, size[u] += size[v];
    }
    int getsize(int u) { return size[findUPar(u)]; }
};
 
int extended_euclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
int modular_inverse(int a, int m)
{
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n], x;
 
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> x;
       long long mx=*max_element(arr,arr+n);
       long long mn=*min_element(arr,arr+n);
       if(x<=mx && x>=mn)
      { cout<<"YES"<<endl ; continue;}
      else cout<<"NO"<<endl;
    }
}