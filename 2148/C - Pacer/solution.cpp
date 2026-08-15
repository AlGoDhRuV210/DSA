#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        int t = 0;
        int side = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            int diff = a - t;
            if (b == side)
                ans += (diff / 2) * 2;
            else
                ans += (1 + ((diff - 1) / 2) * 2);
            t = a;
            side = b;
            if (i == n - 1)
                ans += m - t;
        }
        cout<<ans;
        cout << endl;
    }
 
    return 0;
}
 