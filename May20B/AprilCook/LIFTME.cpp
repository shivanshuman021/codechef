#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,q;
	long long int n,f,d,temp,sum;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>n>>q;
		temp=0;
		sum=0;
		for (int j=0;j<q;++j)
		{
			cin>>f>>d;
			sum+=abs(f-temp);
			sum+=abs(d-f);
			temp = d;
		}	

		cout<<sum<<endl;
	}



	return 0 ;
}