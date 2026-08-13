// 
 
 
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
#define f(i,n) for (int i = 0; i < n; i++)
#define vi vector<long long>
#define pii pair<int, int>
#define vpii vector<pair<int,int>>
#define mii map<int, int>
#define mci map<char, int>
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sort(x) sort(x.begin(),x.end())
#define int long long
 
 
 
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{   string s;
    cin>>s;
    set<char> r;
    for(auto i : s)
    r.insert(i);
    if(r.size() % 2 ==0)
    cout<<"CHAT WITH HER!"<<endl;
    else 
    cout<<"IGNORE HIM!"<<endl;
 
}
 
 
int32_t main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
 
     
       solve();
 
   return 0; 
}