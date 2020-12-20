#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
#include <utility>
#include <list>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

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

void printG(vector<vector<pair<int, int>>> &G)
{
    for (int i = 1; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            cout << G[i][j].first << " " << G[i][j].second << "\n";
        }
        cout << "\n";
    }
    //cout << "\n";
}

void Explore(vector<vector<pair<int, int>>> &G, vector<bool> &visited, int v, int t)
{
    visited[v] = true;
    //cout << v << " ";
    vector<pair<int, int>>::iterator it;
    for (it = G[v].begin(); it != G[v].end(); ++it)
    {
        if (!visited[(*it).first] && (*it).second >= t)
            Explore(G, visited, (*it).first, (*it).second);
    }
}

int DFS(vector<vector<pair<int, int>>> &G, int v, int V)
{
    vector<bool> visited(V, false);

    Explore(G, visited, v, 0);

    int cnt = count(visited.begin(), visited.end(), true);
    //cout << "\n";
    //printvecb(visited);
    return cnt;
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
        //int n = rand() % 3 + 3;
        vector<int> v(n + 1, 0);
        vector<int> count(n + 1, 1);

        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        //srand((unsigned)time(0));
        //for (int i = 1; i <= n; ++i)
        //    v[i] = (rand() % 3) + 3;
        // cout << "\nNew case\n"; ;'

        //printvec(v);
        int tim;

        vector<vector<pair<int, int>>> kono(n + 1, vector<pair<int, int>>());

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

                        //cout << "i = " << i << "j = " << j << " pushed";
                        kono[i].push_back(make_pair(j, tim));
                        kono[j].push_back(make_pair(i, tim));
                    }
                }
            }
        }

        //printG(kono);
        for (int i = 1; i <= n; ++i)
        {
            sort(kono[i].begin(), kono[i].end(), sortbysec);
        }

        for (int i = 1; i <= n; ++i)
        {
            count[i] = DFS(kono, i, n + 1);
            //cout << "day " << i << " count = " << count[i] << "\n";
        }
        //printvec(count);
        // graph completed
        sort(count.begin(), count.end());
        //cout << count[1] << " " << count[n] << "\n";
        cout << count[1] << " " << count[n] << "\n";
    }

    return 0;
}
