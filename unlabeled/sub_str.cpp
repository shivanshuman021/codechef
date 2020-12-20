#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long 
#define M 1000000007

void printmap(map<ll,ll> &m)
{
    cout<<"map :\n";
    for (auto it=m.begin();it!=m.end();++it)
         cout<<it->first<<" "<<it->second<<"\n";
}

ll power(ll x,ll n)
{
    ll res = 1;
    while(n>0)
    {
        if (n%2==1) res = (res*x)%M;
    }
    x = (x*x)%M;
    n = n/2;

    return res;
}

map <ll,ll>::iterator maxel(map <ll,ll> &m)
{
    ll mi,minval = LLONG_MIN;
    
    map <ll,ll>::iterator itr,it;
    for (it = m.begin();it!=m.end();++it)
    {
        if (it->second == minval)
        {
            mi = min(mi,it->first);
        }

        else if (it->second > minval)
        {
            mi = it->first;
            minval = it->second;
        }
    }
    itr = m.find(mi);
    return itr;
}

int emptym(map<ll,ll> &m)
{
    int res = 0;
    map <ll,ll>::iterator itx;
    for (itx = m.begin();itx!= m.end();++itx)
    {
        if (itx->second > 0)
        {
            res = 1;
            break;
        }
    }
    
    cout<<res<<" is res\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int a[n];
        
        for (int i=0;i<n;++i) cin>>a[i];
        cout<<"stage 0\n";
        map <ll,ll> m;//po;

        map <ll,ll>::iterator it,itr,it2,it3;
        for (int i=0;i<n;++i)
        {
            m[a[i]]++;
        }
        
        ll ans=1;
        
        map <ll,ll> fin;

        printmap(m);

        while(true)
        {
            ans =1;
            cout <<"loop 1\n";
            it = maxel(m);
            for (it2 = m.begin();it2!=m.end() ;++it2)
            {
                if (it2==it) continue;
                else{
                    ans = (ans*power(it2->first,it2->second))%M;
                }
            }
            cout<<"ans is "<<ans<<"\n";
            it3 = fin.find(it->first);
            if (it3!=fin.end())
                fin[it->first] += ans;
            else fin[it->first] = ans;
            cout<<m[it->first]<<"\n";
            --m[it->first];
            cout<<m[it->first]<<"\n";
            printmap(m);
            if (emptym(m)==0) break;
        }

        for (ll i=1;i<=n;++i)
        {
            it2 = fin.find(i);
            if (it2!=m.end())
                cout<<it2->second%M<<" ";
            else cout<<0<<" ";
        }
        cout<<"\n";

    }
    return 0;
}