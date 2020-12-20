#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

bool isPrime(int a)
{
    bool p = true;
    for (int i=2;i<=a/2;++i)
    {
        if (a%i == 0)
        {
            p = false;
            break;
        }
    }

    return p;
}

int nextPrime(int a)
{
    int i=a+1;
    while(true)
    {
        if (isPrime(i))
            return i;
        ++i;
    }
}

void printvec(vector<int>&a)
{
    for (int i=1;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void restore(vector<int> &a,vector<int> b,int &p,int &p1,int idx)
{
    // p1 is prime generator whilst p is updater
    // base case
    if (b[idx]==idx)
    {
        p1 = nextPrime(p1);
        if (a[idx]==INT_MAX)
        {
            a[idx] = p1;
            p = p1;
            return;
        }
        else
        {   
            //p = p1;
            a[idx] = a[idx]*p1;
            p = a[idx];
            return;
        }
    }

    restore(a,b,p,p1,b[idx]);
    a[idx] = p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t,n;cin>>t;
    while(t--)
    {
        cin>>n; 
        vector<int> b(n+1,0);
        vector<int> a(n+1,INT_MAX);
        int ax = 1,pr = 1;

        for (int j=1;j<=n;++j) 
            cin>>b[j];
        
        for (int i=1;i<b.size();++i)        
            restore(a,b,ax,pr,i);
        
        /*map<int,vector<int> > m;
        map<int,vector<int> >::reverse_iterator it;
        for (int j=1;j<=n;++j) 
        {
            cin>>b[j];
            (m[b[j]]).push_back(j);
        }
        
        
        for (it=m.rbegin();it != m.rend();++it)
        {
            nextPrime(ax);
            for (int i=0;i<it->second.size();++i)
            {
                a[it->second[i]] = ax;
            }
        }*/

        printvec(a);
    }
    return 0;
}