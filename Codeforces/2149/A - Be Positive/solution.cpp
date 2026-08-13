#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
                x++;
            else if (arr[i] == 0)
                y++;
            else
                continue;
        }
        cout << y + (x % 2) * 2;
        cout<<endl;
    }
 
    return 0;
}