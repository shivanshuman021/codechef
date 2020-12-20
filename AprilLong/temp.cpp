#include <iostream>
#include <vector>

int bittu(long long int n, int k)
{
	if ((n>>(k-1)) & 1) return 1;
	else return 0;
}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int t,n,x1,x2,x3;
	long long int count=0,a;

	std::cin>>t;
	for (int i=0;i<t;++i)
	{
		std::cin>>n;long long int arr[n];
		count = n*(n+1)/2;
		std::vector <int> v;
		for (int j=0;j<n;++j)
		{
			std::cin>>a;
			if (a%2!=0) arr[j] = 0;
			else if (a%4==2) {
				arr[j]=1;v.push_back(j);
				}
			else arr[j]=2;
		}

		for (int j=0;j<v.size();++j)
		{
			x2=v[j];
			x1=x2-1;
			x3=x2+1;


			while(arr[x1]<1) --x1;
			++x1;

			while(arr[x3]<1) ++x3;
			--x3;

			count-=(x3-x2+1)*(x2-x1+1);
		}
		std::cout<<count<<"\n";
	}

	return 0;
}