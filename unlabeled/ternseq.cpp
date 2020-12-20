#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    long x1, x2, y1, y2, z1, z2;
    while (t--)
    {
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        long long sum = 0;
        //2 vs 1
        if (z1 >= y2)
        {
            sum += 2 * y2;
            y2 = 0;
            z1 -= y2;
        }
        else
        {
            sum += 2 * z1;
            z1 = 0;
            y2 -= z1;
        }

        /*if (y1 >= x2)
        {
            x2 = 0;
            y1 -= x2;
        }
        else
        {
            y1 = 0;
            x2 -= y1;
        }*/
        // 2 vs 2
        if (z1 > 0 && z2 > 0)
        {
            if (z1 >= z2)
            {
                z1 -= z2;
                z2 = 0;
            }
            else
            {
                z2 -= z1;
                z1 = 0;
            }
        }

        // 1 vs 1
        if (y1 > 0 && y2 > 0)
        {
            if (y1 >= y2)
            {
                y1 -= y2;
                y2 = 0;
            }
            else
            {
                y2 -= y1;
                y1 = 0;
            }
        }

        // 2 vs 0
        if (z1 > 0 && x2 > 0)
        {
            if (z1 >= x2)
            {
                z1 -= x2;
                x2 = 0;
            }
            else
            {
                x2 -= z1;
                z1 = 0;
            }
        }

        // 1 vs 0
        if (y1 > 0 && x2 > 0)
        {
            if (y1 >= x2)
            {
                y1 -= x2;
                x2 = 0;
            }
            else
            {
                x2 -= y1;
                y1 = 0;
            }
        }
        //0 vs 2
        if (x1 > 0)
        {
            if (z2 > 0)
            {
                if (x1 >= z2)
                {
                    x1 -= z2;
                    z2 = 0;
                }
                else
                {
                    z2 -= x1;
                    x1 = 0;
                }
            }
        }
        // 0 vs 1
        if (x1 > 0)
        {
            if (y2 > 0)
            {
                if (x1 >= y2)
                {
                    x1 -= y2;
                    y2 = 0;
                }
                else
                {

                    y2 -= x1;
                    x1 = 0;
                }
            }
        }

        // 2 vs 0

        if (z1 > 0 && x2 > 0)
        {
            if (z1 >= x2)
            {
                z1 -= x2;
                x2 = 0;
            }
            else
            {
                x2 -= z1;
                z1 = 0;
            }
        }

        // 1 vs 0
        if (y1 > 0 && x2 > 0)
        {
            if (y1 >= x2)
            {
                y1 -= x2;
                x2 = 0;
            }
            else
            {
                x2 -= y1;
                y1 = 0;
            }
        }

        // 0 vs 0
        if (x1 > 0 && x2 > 0)
        {
            if (x1 >= x2)
            {
                x1 -= x2;
                x2 = 0;
            }
            else
            {
                x2 -= x1;
                x1 = 0;
            }
        }

        sum -= (2 * z1);
        sum -= (y1);

        cout << sum << "\n";
    }
}