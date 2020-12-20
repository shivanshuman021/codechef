#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n ;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>n;
		long long int a;
		int arr[n];



		//making arrary of powers of each number

		for (int j=0;j<n;++j)  {
			cin>>a;
			if (a%2==1) a = 0;
			else 
			{
				int p=0;
				while(a%2==0)
				{
					p++;
					a/=2;
				}
				a=p;
			}

			arr[j] = a;
		}

		int count =0;
		for (int j =0;j<n;j++)
		{
			if (arr[j]>1) count+=(n-j);
			else if (arr[j]==1)
			{
				int k=j+1;
				while(arr[k]<1) k++;
				count+= (n-k);
			}

			else
			{
				int k=j+1;
				while(arr[k]<1) k++;
				count+=(k-j);
				
				
				if (arr[k]>1) count+=(n-k);
				else if (arr[k]==1)
				{
					k++;
					while(arr[k]<1) k++;
					
					count+=(n-k);
				}
			}

		}

		cout<<count<<"\n";

	}
	return 0;
}
