#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int t,n,m,k,c;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>n>>m>>k;
		for (int j=0;j<n;++j)
		{
			map <int,int> m;
			for (int u=0;u<k;u++)
			{
				cin>>c;
				m[c]++;
			}
			map<int,int>::iterator x = max_element(m.begin(),m.end(), [](const pair<int,int> &a,const pair<int,int>&b)->bool {return a.second < b.second;});
			cout<<x->first<<" ";
		}
	}
	return 0;
}