#include <bits/stdc++.h>
 
using namespace std;
long long gcd(long long x, long long y) {
    while (y != 0) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int x, ans, flag = 0;
        for (long long int i = 2; i <= 1000000; i++)
        {
            x = i;
            for (int j = 0; j < n; j++)
            {
                if (gcd(x, arr[j]) == 1)
                {
                    cout << x;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            cout << "-1";
 
        cout << endl;
    }
 
    return 0;
}