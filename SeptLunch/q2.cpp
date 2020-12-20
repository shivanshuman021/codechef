#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        vector <int>a(n+1,0);
        vector<int>b(n+1,0);
        
        for (int i=1;i<=n;++i)
        {
            cin>>b[i];
        }
        int o=0,out=0;
        for (int i=1;i<=n;++i)
        {
            if (b[i]<0 || b[i]>i)
            {
                cout<<"NO\n";
                out=1;
                break;
            }
            if (b[i]==i || b[i]==1)
            {
                continue;
            }
            
            else
            {
                o=0;
                if (i%2==0)
                {
                    if (b[i]%2==1)
                    {
                        cout<<"NO\n";
                        out=1;
                        break;
                    }
                    else{
                        for (int j=2;j<=i;j+=2)
                        {
                            if (__gcd(i,j)==b[i])
                            {
                                o=1; 
                            }
                        }
                    
                    
                    
                        if (o==0)
                        {
                            cout<<"NO\n";
                            out=1;
                            break;
                        }
                    }
                }
                else
                {
                    o=0;
                    if (b[i]%2==0)
                    {
                        cout<<"NO\n";
                        out=1;
                        break;
                    }
                    
                    else
                    {
                        for (int j=3;j<=i;j+=2)
                        {
                            if (__gcd(i,j)==b[j])
                            {
                                o=1;
                            }
                        }
                        
                        if (o==0)
                        {
                            cout<<"NO\n";
                            out=1;
                            break;
                        }
                    }
                }
                
            }
            
        }
        
        if (out==0) cout<<"YES\n";
        
        
	}

	return 0;
}