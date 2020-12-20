#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<long> &v)
{
    for (long i = 1; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void DFS(vector<vector<int>> &adj, vector<bool> &visited, vector<long> &b, vector<long> &d, vector<long> &p, long Api, long start, long day)
{
    visited[start] = true;
    if (b[start] > 0)
    {
        b[start] -= min(b[start], Api);
        d[start] = day;
    }
    //cout << "city " << start << " visited\n";
    for (long i = 1; i < adj.size(); ++i)
    {
        if (adj[start][i] == 1 && (!visited[i]))
        {
            DFS(adj, visited, b, d, p, Api, i, day);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    long n, u, v;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        for (long i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        /*for (long i = 1; i < n + 1; ++i)
        {
            for (long j = 1; j < n + 1; ++j)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }*/

        vector<long> p(n + 1, 0);
        vector<long> a(n + 1, 0);
        vector<long> b(n + 1, 0);
        vector<long> d(n + 1, 0);

        long x;

        for (long i = 1; i < p.size(); ++i)
        {
            cin >> x;
            p[i] = x;
        }

        for (long i = 1; i < a.size(); ++i)
        {
            cin >> x;
            a[i] = x;
        }

        for (long i = 1; i < b.size(); ++i)
        {
            cin >> x;
            b[i] = x;
        }

        for (long i = 1; i < p.size(); ++i)
        {
            //cout << "\nday " << i << "\n";
            vector<bool> visited(n + 1, false);
            DFS(adj, visited, b, d, p, a[p[i]], p[i], i);
            // remove connections of p[i] to all other nodes
            for (long j = 1; j < adj.size(); ++j)
            {
                adj[p[i]][j] = 0;
                adj[j][p[i]] = 0;
            }
            //cout << "fruits :\n";
            //printvec(b);
        }
        //cout << "fruits vector : ";
        //printvec(b);

        //cout << "day vector : ";
        for (long i = 1; i < d.size(); ++i)
        {
            if (b[i])
            {
                cout << -1 << " ";
            }
            else
            {
                cout << d[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}