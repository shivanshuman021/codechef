#include <iostream>

using namespace std;

int main()
{
	int t;cin>>t;
	int n;short int a;
	for (int i = 0;i<t;i++)
	{
		cin>>n;	int arr[n];

		for (int i =0;i<n;i++) cin>>arr[i];


		int k = 0;
		while (k<n)
		{
			if (arr[k]==1) {break;}
			else k++;
		}


		if (k==n-1)
		{
			cout<<"YES\n";continue;
		}
		else k++;
	
		int count =0;
		for (k;k<n;k++)
		{
			
			if (arr[k]==0) count++;
			else 
			{
				if (count>=0 && count<5) {cout<<"NO\n";break;}
				else{
					count=0;
				}
			}
		}

		if (k==n) cout<<"YES\n";

	}
	return 0;
}