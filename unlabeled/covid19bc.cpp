#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <utility>
#include <list>

using namespace std;
void printvec(vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printvecb(vector<bool> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        vector<int> v(n + 1, 0);

        int k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> k;
            v[i] = k;
        }
        int tim;

        map<int, vector<int>> m;
        map<int, vector<int>>::iterator mit;
        vector<int>::iterator vit;

        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (v[j] >= v[i])
                    continue;

                else
                {
                    if ((j - i) % (v[i] - v[j]) == 0)
                    {
                        tim = ((j - i) / (v[i] - v[j]));

                        vit = find(m[tim].begin(), m[tim].end(), i);
                        if (vit == m[tim].end())
                        {
                            m[tim].push_back(i);
                        }

                        vit = find(m[tim].begin(), m[tim].end(), j);
                        if (vit == m[tim].end())
                        {
                            m[tim].push_back(j);
                        }
                    }
                }
            }
        }

        for (mit = m.begin(); mit != m.end(); ++mit)
        {
            cout << mit->first << "->";
            for (vit = (mit->second).begin(); vit != (mit->second).end(); ++vit)
            {
                cout << *vit << " ";
            }
            cout << "\n";
        }

        bool o;

        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            map<int, vector<int>> ma = m;
            vector<bool> visited(n + 1, false);
            visited[i] = true;
            o = false;
            for (mit = ma.begin(); mit != ma.end(); ++mit)
            {
                for (vit = (mit->second).begin(); vit != (mit->second).end(); ++vit)
                {
                    if (visited[(*vit)] == true)
                    {
                        o = true;
                        break;
                    }
                }

                if (o == true)
                {
                    for (vit = (mit->second).begin(); vit != (mit->second).end(); ++vit)
                    {
                        visited[(*vit)] = true;
                    }
                }
            }

            cnt[i] = count(visited.begin(), visited.end(), true);
        }

        printvec(cnt);

        sort(cnt.begin(), cnt.end());
        cout << cnt[1] << " " << cnt[n] << "\n";
    }

    return 0;
}
