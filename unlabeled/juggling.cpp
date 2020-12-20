#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        char k;
        map <char,long> m;
        for (int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            stringstream ss(s);
            while(ss>>k)
            {
                m[k]++;
            }
        }
        int o=0;
        for (auto it=m.begin();it!=m.end();++it )
        {
            if ((it->second)%n!=0)
            {
                cout<<"NO\n";
                o=1;
                break;
            }
        }
        
        if (o==0)
        {
            cout<<"YES\n";
        }
    }
    
    return 0;
}
