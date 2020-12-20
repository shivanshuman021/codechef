#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;cin>>t;
    long x,p,k,n;
    while(t--)
    {
        cin>>n>>x>>p>>k;
        vector<long>v;
        long q;
        for (int i=0;i<n;++i)
        {
            cin>>q;
            v.push_back(q);
        }

        if (v[p-1]==x)
        {
            cout<<0<<endl;
        }
        else if (v[p-1]<x)
        {
            cout<<-1<<"this"<<endl;
        }
        else
        {
            sort(v.begin(),v.end());
            if (p==k)
            {
                if (v[p-1]!=x)
                {
                    cout<<1<<endl;
                }
            }
            else if (p<k)
            {
                int idx=0;
                bool flg =false;
                int j;
                for (j=0;j<n;++j)
                {
                    idx = j;
                    if (v[j]<=x)
                    {
                        if (v[j]==x) flg = true;
                        continue;
                    }
                    else break;
                }

                if (flg)
                {
                    while(v[idx]==x)
                    {
                        ++idx;
                    }
                    --idx;
                }
                int ans=0;
                if (v[idx]==x)
                {
                    ans = abs(p-1-idx);
                }
                else{
                    ans = abs(p-1-idx);
                }
                //cout<<p<<" "<<idx<<endl;
                cout<<ans<<endl;
            }

            else{
                cout<<-1<<endl;
            }

            
        }
    }

    return 0;
}