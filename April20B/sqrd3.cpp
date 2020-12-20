
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
	long long int a,count=0;
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
		
		int x1,x2=0;
		count =0;
		int zeros =0;
		int one=0;
		for (int j=0;j<n;++j)
		{
			if (arr[j]==2){
			    if (zeros>0){
				count+=(zeros*(zeros+1))/2 ;
				//std::cout<<(zeros*(zeros+1))/2<<"\n";
				zeros=0;
			    }
			    
				count+=(n-j);
				//std::cout<<(n-j)<<"\n";
				if (one==1){
					//x2 = j;
					count+=(n-j);
					//std::cout<<(n-j)<<"\n";
					one=0;
				}
				
			}

			else if (arr[j]==1){
				if (zeros>0){
				    count+=(zeros*(zeros+1))/2;
//				    std::cout<<(zeros*(zeros+1))/2<<"\n";
				    zeros=0;
				}
				
				if (one==1){
					//x2 = j;
					count+=(n-j);
					//std::cout<<(n-j)<<"\n";
					one=0;
				}
				
				else{
					one=1;
					x1=j;
					//continue;
				}
			}

			else {++zeros;}//continue;}
		}

		if(zeros) count+=zeros*(zeros+1)/2;

		std::cout<<count<<"\n";
	}
	return 0;
}