#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isCoprime(int n,int m)
{
	if (__gcd(n,m) == 1) return true;
	else return false;
}

int main()
{
	int t,n;
	for (int i=0;i<t;++i)
	{
		cin>>n;
		int arr[n];
		for (int j=0;j<n;j++)
		{
			arr[j] = j+1;
		}
		vector<int> v;

		for (int j=0;j<n;j++)
		{
			
		}




	}
	return 0;
}