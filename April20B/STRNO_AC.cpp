#include <iostream>
#include <cmath>



long long int prime(long long int x)
{
	long long int div=0;
	while (x%2==0) {++div;x=x/2;}

	for (long long int i =3;i<sqrt(x);++i)
	{
		while(x%i==0) {++div;x=x/i;}
	}

	if (x>2) ++div;

	return div;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin>>t;
	long long int x,k;
	for (int i=0;i<t;++i)
	{
		std::cin>>x;
		std::cin>>k;
		if(prime(x)>k) std::cout<<"0\n";
		else std::cout<<"1\n";

	}
	return 0;
}