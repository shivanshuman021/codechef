#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned int t,n ;
	
	cin>>t;
	for (int p=0;p<t;++p)
	{
		cin>>n;
		unsigned int x[n];
		vector <int> v;
		
		for (int i=0;i<n;++i) {cin>>x[i];}
		int diff[n-1];

		for (int i=1;i<n;++i) {
			diff[i-1] = x[i]-x[i-1];
			diff[i-1]=abs(diff[i-1]);
		}
		//cout<<"differences : ";
		//for (int i=0;i<n-1;++i)	cout<<diff[i]<<" ";cout<<endl;
	
		int i =0,j=0;
		int count =1;
		//cout<<"Count : ";
		for (i=0;i<n-1;)
		{
			if (diff[i]<3) {
				++count;++i;
				//cout<<count<<" ";
			}

			else if (diff[i]>2)
			{
				//cout<<count<<" ";
				//if (count>1) {
				v.push_back(count);
				count =1;
				++i;
			}
		
			if (i==n-1) {
				v.push_back(count);
				//cout<<count<<" ";
			}
		}
	
		sort(v.begin(),v.end(),greater <int> ());

		//cout<<"sorted counts ";
		//for (int j=0;j<v.size();++j) cout<<v[j]<<" ";cout<<"\n";
		int s =v.size()-1;
		cout<<v[s]<<" "<<v[0]<<"\n";
		//if (s==0) cout<<1<<" "<<1<<"\n";
	
		}	
	return 0;
}