#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t,n ;
	long long int a,
	count=0;
	std::cin>>t;
	for (int i=0;i<t;i++)
	{
		std::cin>>n;
		
		long long int arr[n];

		//making arrary of powers of each number
		for (int j=0;j<n;++j)  
			std::cin>>arr[j];

		for (int j=0;j<n;++j){
			a = arr[j];
			if (a%2!=0) arr[j] = 0;
			else if (a%2==0)
			{
				if (a%4!=0) arr[j] = 1;
				else if (a%4==0) arr[j] =2;
			}
		}


		int k=0;
		count =0;
		for (int j=0;j<n;++j)
		{
			k=j+1;
			if (arr[j]==2) count+=(n-j);
			else if (arr[j]==1)
			{
				while(arr[k]<1) ++k ;
				count+= (n-k);
			}

			else
			{	
				while(arr[k]<1) ++k;
				
				count+=(k-j);
				
				
				if (arr[k]==2) count+=(n-k);
				else if (arr[k]==1)
				{
					++k;
					while(arr[k]<1) ++k;
					
					count+=(n-k);
				}
			}

		}

		std::cout<<count<<"\n";

	}
	return 0;
}