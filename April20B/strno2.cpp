#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
//#define MAX 1000000

//int s[MAX];
/*
long long int C(long long int n,long long int r)
{	
	if (r> n-r) r = n-r;
	long long no = 1;

	for (int i =1;i<=r;++i)
	{
		no*= n-r+i;
		no /= i;
	}

	return no;
}
*/
void seive(long long int s[],int size)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	s[1]=1;
	for (int i=2;i<size;i+=2) s[i] = 2;

	for (int i=3;i*i<size;i++)
	{
		if (s[i]==i)
		{
			for (int j = i*i;j<size ; j+=i)
			{
				if (s[j]==j) s[j]=i;
			}
		}
	}
}


vector <long long int> factors(long long int s[], int size,long long int X)
{
	vector <long long int> v;

	while (X!=1)
	{
		v.push_back(s[X]);
		X = X / s[X];
	}

	return v;
}

int main()
{
	int t;long long int x,k;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		cin>>x>>k;
		long long int s[sqrt(x)];
		int size = sqrt(x);
		seive(s,size);
		map<int,int> m;
		vector <long long int> v = factors(x);

		for (int j=0;j<v.size();++j)
		{
			m[v[j]]++;
		}

		map<int,int>::iterator itr;

		long long int ncr = 1;
		for (itr= m.begin();itr != m.end() ; ++itr)
		{
			ncr*=C((itr->first)+k-1,k-1);
		}

		if (ncr) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}