#include <iostream>

int bittu(long long int n, int k)
{
	if ((n>>(k-1)) & 1) return 1;
	else return 0;
}

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

		
		for (int j=0;j<n;++j)
		{  
			std::cin>>a;
			if (bittu(a,1)) arr[j]=0;
			else
			{
				if (bittu(a,2)) arr[j]=1;
				else arr[j] = 2;
			}

		}
		


		int k=0;
		count =0;
		for (int j=0;j<n;++j)
		{
			k=j+1;
			if (arr[j]==2) {
				count+=(n-j);}
		
			else if (arr[j]==1)
			{
		
				while(arr[k]<1 & k<n) ++k ;
				count+= (n-k); 
		
			}

			else
			{	
		
				while(arr[k]<1 & k<n) {
					++k;
		
				}
				
				count+=(k-j);
		
				
				
				if (arr[k]==2) {
					count+=(n-k);
				}
				else if (arr[k]==1)
				{
		
					++k;
					while(arr[k]<1 & k<n){
					 ++k;
		
					}
					
					count+=(n-k);
		
				}
			}

		}

		std::cout<<count<<"\n";

	}
	return 0;
}