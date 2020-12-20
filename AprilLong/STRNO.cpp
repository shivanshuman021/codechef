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

int primeFactors(int N,long long int x,long long int k)
{
	long long int div=1;long long int primeDiv=0;
	int s[N+1];
	seiveofEratosthenes(N,s);

	int curr = s[N];
	int cnt = 1;

	while (N>1)
	{
		N/=s[N];

		if (curr == s[N])
		{
			cnt++;
			continue;
		}
		primeDiv++;
		curr = s[N];
		div *= (cnt+1);
		cnt =1;
	}

	
	if (primeDiv == k && div ==x ) return 1;
	else return 0;
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
		int j =2;
		for (j;j<=INT_MAX;++j)
		{
			if (primeFactors(j,x,k)==1) {cout<<"1\n";break;}
			else continue;
		}
		if (primeFactors(j,x,k)==0) {cout<<"0\n";}
	}
	return 0;
}