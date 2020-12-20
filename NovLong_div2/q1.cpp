#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t,n;cin>>t;
    while(t--)
    {
        cin>>n;int c[n];
        for (int k=0;k<n;++k) cin>>c[k];

        int set=0,nset=0,x,ans = INT_MAX;
        for (int i=0;i<(1<<n);++i)
        {
            set = 0;nset=0;
            x = i;

            for (int j=n-1;j>=0;--j)
            {
                if (x&1) set+=c[j];
                else nset+=c[j];
                
                x=x>>1;
            }

            if (ans > max(set,nset))
            {
                ans = max(set,nset);
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}