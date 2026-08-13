#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            cout << "2";
        else if (x == y)
            cout << "-1";
        else
        {
            if ((x - y) > 1 && y != 1)
                cout << "3";
            else
                cout << "-1";
        }
        cout << endl;
    }
 
    return 0;
}