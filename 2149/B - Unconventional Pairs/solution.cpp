#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main()
{
    int t;
    
    cin >> t;
    while (t--)
    {int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // sorted array
        sort(arr,arr+n);
        int diff, max_diff = abs(arr[1] - arr[0]);
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(arr[i + 1] - arr[i]) > max_diff)
                max_diff = abs(arr[i + 1] - arr[i]);
             i++;
 
        }
        cout << max_diff;
        cout<<endl;
    }
    return 0;
}