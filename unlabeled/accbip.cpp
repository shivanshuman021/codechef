#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, k, c, z;

    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> n >> c >> k;

        vector<int> m(c + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> z;
            m[z]++;
        }

        vector<int> v(c + 1, 0);
        int w;
        for (int i = 1; i < c + 1; ++i)
        {
            cin >> w;
            v[i] = w;
        }
        //vector<int> vc;
        if (*min_element(v.begin() + 1, v.end()) == *max_element(v.begin() + 1, v.end()))
        {
            int co = v[0];
            int r = k / co;

            while (r > 0)
            {
                sort(m.begin() + 1, m.end());
                if (m[c] > 2)
                    --m[c];
                else
                    break;
                --r;
            }

            long long ans = 0, g;
            for (int i = 0; i <= c; ++i)
            {
                g = m[i];
                ans += (((g) * (g - 1) * (g - 2)) / 6);
            }

            cout << ans << "\n";
        }
        else
        {
            vector<int> rate(c + 1);
            for (int i = 1; i < rate.size(); ++i)
            {
                rate[i] = (((m[i] - 1) * (m[i] - 2)) / (2 * v[i]));
            }
            int q = *min_element(v.begin() + 1, v.end());
            vector<int>::iterator it;
            while (k >= q)
            {
                it = max_element(rate.begin() + 1, rate.end());
                m[it - m.begin()]--;
                k--;
                rate[it - m.begin()] = (((m[i] - 1) * (m[i] - 2)) / (2 * v[i]));
            }
            long long ans = 0, g;
            for (int i = 0; i <= c; ++i)
            {
                g = m[i];
                ans += (((g) * (g - 1) * (g - 2)) / 6);
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
