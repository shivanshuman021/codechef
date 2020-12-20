#include <iostream>
#include <map>
#include <climits>
#include <cmath>

using namespace std;
#define ll long long
#define M 1000000007

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

void printmap(map<ll,ll> &m)
{
    cout<<"map :\n";
    for (auto it=m.begin();it!=m.end();++it)
         cout<<it->first<<" "<<it->second<<"\n";
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

int main()
{
    map<ll,ll> m ;
    m[1]=5;m[2]=2;m[3]=5;m[4]=2;

    int k = emptym(m);
    auto it = maxel(m);

    ll ans = ans*power(it->first,it->second);
    cout<<"ans is "<<ans<<"\n";

    return 0;
}