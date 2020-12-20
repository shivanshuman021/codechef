#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void seiveofEratosthenes(long long int N,int s[])
{
	vector <bool> prime(N+1, false);

	for (int i=2;i<=N ; i+=2) s[i] = 2;
	for (int i=3;i<=N;i+=2)
	{
		if (prime[i]==false)
		{
			s[i]=i;
			for (int j=i;j*i<=N;j+=2)
			{
				if (prime[i*j]==false)
				{
					prime[i*j] = true;
					s[i*j] = i;
				}
			}
		}
	}
}

int primeFactors(long long int x)
{
	//long long int div=1;
	long long int primeDiv=0;
	int s[x+1];
	seiveofEratosthenes(x,s);

	int curr = s[x];
	int cnt = 1;

	while (x>1)
	{
		x/=s[x];

		if (curr == s[x])
		{
			cnt++;
			continue;
		}
		primeDiv++;
		curr = s[x];
		//div *= (cnt+1);
		cnt =1;
	}

	return primeDiv;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int x,k;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>x>>k;
		cout<<"No of prime factors of x are :"<<primeFactors(x)<<"\n";
	}
	return 0;
}