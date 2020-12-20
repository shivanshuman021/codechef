#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printvec(vector<long> v)
{
    for (long i = 1; i <= v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void eat(vector<vector<long>> &joint, vector<bool> &v, vector<long> &d, vector<long long> &b, vector<long long> &a, long long Api, long ind, long ancstr, long day)
{
    //cout<<"eat called for : "<<ind<<"\n";

    //if (b[ind] <= 0)
    //{
    //cout<<"\nind has already 0 fruits\n";
    //    return;
    //}

    //if (v[ind] == true)
    //    return;

    if (joint.size() == 0)
        return;

    vector<long>::iterator it, itr;
    //if (v[ind] == false)
    //{
    //b[ind] -= min(b[ind], Api);
    //d[ind] = day;
    //v[ind] = true;
    //}
    //cout<<"eated in city "<<ind<<" on day "<<day<<"fruits : \n";
    //printvec(b);

    for (it = joint[ind].begin(); it != joint[ind].end(); ++it)
    {
        itr = find(joint[*it].begin(), joint[*it].end(), ancstr);
        if (itr != joint[*it].end())
            joint[*it].erase(itr);
        if (v[*it] == false)
        {
            if (b[*it] > 0)
            {
                b[*it] -= min(b[*it], Api);
                d[*it] = day;
            }
            v[*it] == true;
            eat(joint, v, d, b, a, Api, *it, ancstr, day);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    long n, u, v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<long> p(n + 1, 0);
        vector<long long> a(n + 1, 0);
        vector<long long> b(n + 1, 0);
        vector<long> d(n + 1, 0);
        vector<vector<long>> joint(n + 1);
        for (long i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            joint[u].push_back(v);
            joint[v].push_back(u);
        }

        long x;
        long long y;

        for (long i = 1; i <= n; ++i)
        {
            cin >> x;
            p[i] = x;
        }

        for (long i = 1; i <= n; ++i)
        {
            cin >> y;
            a[i] = y;
        }

        for (long i = 1; i <= n; ++i)
        {
            cin >> y;
            b[i] = y;
        }

        for (long i = 1; i <= n; ++i)
        {
            vector<bool> v(n + 1, false);
            //cout<<"\nIteration : "<<i<<"\n\n";
            v[p[i]] = true;
            if (b[p[i]] > 0)
            {
                b[p[i]] -= min(b[p[i]], a[p[i]]);
                d[p[i]] = i;
            }
            eat(joint, v, d, b, a, a[p[i]], p[i], p[i], i);
            joint[p[i]].clear();
        }

        //cout << "fruits on last day are:\n";
        /*for (long i = 1; i < b.size(); ++i)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "days on which finished\n";*/
        for (long i = 1; i < d.size(); ++i)
        {
            if (b[i] == 0)
                cout << d[i] << " ";
            else
                cout << -1 << " ";
        }
        cout << "\n";
    }

    return 0;
}