#include <iostream>
using namespace std;

int bin(int x)
{
	int no=0;
	int base=1;

	while(x)
	{	
		no+=(base*(x%2));
		base=base*10;
		x = x/2;
	}

	return no;
}

void output(unsigned long long int b[],unsigned long long int size)
{
	int c=0,odd_1s=0,even_1s=0;
	for (int i=0;i<size;i++)
	{
		
		c=__builtin_popcount(b[i]);

		if (c%2==0) even_1s++;
		else odd_1s++;
	}

	cout<<even_1s<<" "<<odd_1s<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    unsigned int t;cin>>t;unsigned long long int n,q,p;
    for (int i=0;i<t;i++)
    {
    	cin>>n>>q;unsigned long long int a[n];
    	for (int i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	
    	unsigned long long int b[n];
    	for (int i=0;i<q;i++)
    	{
    		cin>>p;
    		for (int j=0;j<n;j++)
    		{
    			b[j]=bin(p^a[j]);
       		}

    		output(b,n);
    	}
    }
    return 0;
}