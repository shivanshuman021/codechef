#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t,n;
	long long int prod =1;int count=0;
	cin>>t;
	for (int i=0;i<t;i++)
	{	
		count=0;
		cin>>n;
		long long int arr[n];

		for (int j=0;j<n;j++) cin>>arr[j];

		for (int j=0;j<n;j++)
		{
			prod = 1;
			for (int k =j;k<n;k++)
			{
				prod*=arr[k];
				if (prod %4==0 || prod%2==1) count++;
			}
		}

		cout<<count<<"\n";
	}

	return 0;
}