#include<bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= mx) ans++;
        mx = max(mx, a[i]);
    }
    cout << ans << "
";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}