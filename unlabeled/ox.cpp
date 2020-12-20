#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    long n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n >= k)
        {
            if (n % 2 == 0 && k % 2 == 0)
            {
                cout << 0 << "\n";
            }
            else if (n % 2 == 1 && k % 2 == 1)
            {
                cout << 0 << "\n";
            }
            else
                cout << 1 << "\n";
        }

        else
        {
            cout << abs(n - k) << "\n";
        }
    }

    return 0;
}