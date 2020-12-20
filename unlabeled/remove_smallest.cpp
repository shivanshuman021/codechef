#include <iostream>
#include <map>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		map <int,int> m;
		int a;
		for (int i =0;i<n;++i)
		{
			cin>>a;m[a]++;
		}
		
		map <int,int>::iterator it;
		it = m.begin();
		int p = it->first;int o =0;
		++it;
		for (it;it != m.end();++it)
		{
			if (it->first - p >1) 
			{
				cout<<"NO\n";o=1;
				break;
			}
			p = it->first;
			
		}
		if (o==0) cout<<"YES\n";
		
	}
	
	return 0;
}
			
		