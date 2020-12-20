#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t,n,p ;
	std::cin>>t;
	for (int i=0;i<t;i++)
	{
		std::cin>>n;
		long long int a;
		int arr[n];
		//making arrary of powers of each number

		for (int j=0;j<n;++j)  
			std::cin>>arr[j];

		for (int j=0;j<n;++j){
			if (arr[j]%2!=0) arr[j] = 0;
			else 
			{
				p=0;
				while(a%2==0)
				{
					++p;
					arr[j]=arr[j]/2;
				}
				arr[j]=p;
			}

			
		}

		long long int count =0;
		for (int j =0;j<n;++j)
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

		std::cout<<count<<"\n";

	}
	return 0;
}
