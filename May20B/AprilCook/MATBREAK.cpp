#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;int n;
	long long int a;
	long long int po,l,sum=0;
	cin>>t;
	for (int i=0;i<t;++i)
	{
	    cin>>n>>a;
	    l=0;
	    po=1;sum=0;
	    for (int j=1;j<=n;++j)
	    {
	        po=(l+1)*(2*j-1);
	        l+=po;
	        sum+=pow(a,po);
	        sum= sum %(1000000007);
	    }
	    
	    cout<<sum %(1000000007)<<endl;
	}
	return 0;
}
