#include <iostream>
#include <vector>
using namespace std;

vector <int> prime(int n)
{
	vector<int> v;
	int fact =1;
	for (int k=2;k<=n;++k)
	{
		fact = fact*(k-1);
		if ((fact+1) % k ==0) v.push_back(k);
	}

	return v;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> v;
	int t,n;
	cin>>t;
	for (int i=0;i<t;++i)
	{	
		cin>>n;
		v = prime(n);
		for (int j=0;j<v.size();++j) cout<<v[j]<<" ";






	}
	return 0;
}