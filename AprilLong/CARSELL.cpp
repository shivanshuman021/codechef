#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n;
	long long int sum;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		sum=0;
		cin>>n;long long int arr[n];
		for (int k=0;k<n;k++)
		{
			cin>>arr[k];
		}

		sort(arr,arr+n,greater<long long int>());

		int j= n-1;
		while((arr[j]-j)<=0) 
			j--;

		for (int l=0;l<=j;l++)
		{
			sum+=arr[l];
		}

		long long int d = (j*(j+1))/2;
		sum = sum-d;
		cout<<(sum%1000000007)<<"\n";
	}



	return 0;
}