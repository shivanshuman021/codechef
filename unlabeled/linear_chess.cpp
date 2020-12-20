#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool sortin(const pair <long,long> &a,const pair <long,long> &b)
{
    return (a.second<b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;cin>>t;long k,p;
    while(t--)
    {
        cin>>n>>k;
        //vector < pair <long,long> > v;
        pair <long,long> l = make_pair(LONG_MAX,LONG_MAX);
        for (int i=0;i<n;++i)
        {
            cin>>p;
            if (p>k) continue;
            else if (k%p==0)
            {
                if (k/p <= l.second)
                {
                    l.first = p;
                    l.second = k/p;
                }
            }
        }

        if (l.first < LONG_MAX )
        {
            cout<<l.first<<endl;
        }
        else cout<<-1<<endl;
        /*for (int i=0;i<n;++i)
        {
            cin>>p;
            if (p>k) v.push_back(make_pair(p,LONG_MAX));
            else if (k%p==0)
            {
                v.push_back(make_pair(p,k/p));
            }
            else
            {
                v.push_back(make_pair(p,LONG_MAX));
            }

            
        }
        sort(v.begin(),v.end(),sortin);

        for (int i=0;i<v.size();++i)
        {
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }

        if (v[0].first < LONG_MAX)
        {
            cout<<v[0].first<<"\n";
            
        }
        else cout<<-1<<"\n"; 
            
    }
    cout<<LONG_MAX<<"\n";*/
    }
    return 0;
}