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
        if (n == 1)
        {
            cout << "1";
            cout << endl;
            continue;
        }
        if (n == 2)
        {
            cout << "2";
            cout << endl;
            continue;
        }
        if (n == 3)
        {
            cout << "3";
            cout << endl;
            continue;
        }
        if (n % 2 == 0)
            cout << "0";
        else
            cout << "1";
 
        cout << endl;
    }
 
    return 0;
}