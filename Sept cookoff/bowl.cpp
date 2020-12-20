#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	long t,n,l,k;
	cin>>t;

	while(t--)
	{
		cin>>n>>k>>l;
        long long p = k*l;
		if (p<n)
		{
			cout<<-1<<"\n";
		}
		else
		{
			if (n>1 && k==1)
			{
				cout<<-1<<"\n";
			}
			else{
			for (int i=0;i<(n/k);++i)
			{
				for (int j=1;j<=k;++j)
				{
					cout<<j<<" ";
				}
			}

			for (int i=1;i<=(n%k);++i)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
		}
	}
	return 0;
}