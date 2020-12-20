#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int t, x, n;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cin >> x;
        n = s.length();
        char w[n];
        int i = 0;

        for (i = 0; i < n; ++i)
            w[i] = 'p';

        for (i = 0; i <= x; ++i)
        {
            if (s[i] == '0')
                w[i + x] = '0';
            else
                w[i + x] = '1';
        }

        for (i = n - x + 1; i < x; ++i)
        {

            if (s[i] == '0' && w[i - x] == '0')
                w[i - x] = '0';
            else if (s[i] == '1' && w[i - x] == '1')
                w[i - x] = '1';
            else
            {
                cout << -1 << endl;
                break;
            }
        }

        for (i = 0; i < n; ++i)
        {
            if (w[i] == 'p')
            {
                if (i >= x && (s[i - x] == '1' || s[i + x] == '1'))
                    w[i] = '1';
                else
                    w[i] = '0';
            }
        }

        cout << w << endl;
    }
}