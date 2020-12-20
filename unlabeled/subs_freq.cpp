#include <iostream>
#include <map>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;long n;cin>>t;
    while(t--)
    {
        cin>>n;
        long a[n];
        for (int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        
        map<long,long long> fin;        
        map<long,long long>::iterator it;

        long mi = INT_MIN;
        long long minval;
        map<long,long long> m;
        for (long i=1;i<(1<<n);++i)
        {
            for(long j=0;j<n;++j)
            {
                if ((1<<j)&i)
                {
                    m[a[j]]++;                    
                }
            }
            mi = LONG_MAX;
            minval = LONG_MIN;
            for (it = m.begin();it!=m.end();++it)
            {
                if (it->second == minval)
                {
                    mi = min(mi,it->first);
                }
                else if (it->second >minval)
                {
                    minval = it->second;
                    mi = it->first;
                }
            }
            fin[mi] = (fin[mi]+1)%1000000007;
            m.clear();
        }
        
        for (long i=1;i<=n;++i)    
        {
            it = fin.find(i);
            if (it!= fin.end())
            {
                cout<<it->second%1000000007<<" ";
            }
            else
            {
                cout<<0<<" ";
            } 
            
        }
        cout<<"\n";

    }
    return 0;
}