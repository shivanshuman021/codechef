#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int w[n];
        for (int i = 0; i < n; ++i)
            cin >> w[i];

        vector<bool> pick(n, false);
        long sum = 0;
        int count = 0;
        while (true)
        {
            sum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (sum + w[i] > k)
                {
                    break;
                }
                else
                {
                    sum += w[i];
                    w[i] = 0;
                    pick[i] = true;
                }
            }
            if (sum == 0)
                break;

            else
                ++count;
        }

        if (w[n - 1] > 0)
        {
            cout << -1 << "\n";
        }
        else if (w[n - 1] == 0)
        {
            cout << count << "\n";
        }
    }

    return 0;
}