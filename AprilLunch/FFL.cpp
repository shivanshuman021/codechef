#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n,s,a,dsize,fsize;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		dsize=0;
		fsize=0;
		cin>>n>>s;
		int P[n];
		int d[n];
		int f[n];
		for (int j=0;j<n;++j) cin>>P[j];

		for (int j=0;j<n;++j)
		{
			cin>>a;
			if (a) {f[fsize]=P[j];++fsize;}
			else {d[dsize]=P[j];++dsize;}
		}

		sort(d,d+n);
		sort(f,f+n);

		if ((d[0]+f[0])<=(100-s)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

	return 0;
}