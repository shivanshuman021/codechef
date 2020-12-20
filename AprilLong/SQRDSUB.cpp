#include <iostream>
#include <cmath>
using namespace std;

int subseq(long long int arr[],int beg , int end)
{
	long long int prod =1 ;
	for (int j=beg;j<=end;++j) prod*=arr[j];
	

	long long int q,p;
	for (p=1;p<=int(sqrt(prod)+1);++p)
	{
		for (q=0;q<p;++q)
		{
			//cout<<"arr[beg] = "<<arr[beg]<<" arr[end] = "<<arr[end]<<" Value of p = "<<p<<" q = "<<q<<" prod = "<<prod<<" p^2 - q^2 = "<<(pow(p,2)-pow(q,2))<<endl;
			if ((pow(p,2)-pow(q,2))==prod) {/*cout<<"1 was returned when "<<"p="<<p<<" q="<<q<<"prod ="<<prod<<endl;*/return 1;break;}
			else continue;
		}
	
	}
	    	
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t , n ;
	cin>>t;
	for (int k=0;k<t;k++)
	{
		cin>>n;
		long long int arr[n];
		for (int j=0;j<n;j++)
		{
			cin>>arr[j];
		}

		int count=0;
		for (int i=0;i<n;i++)
		{
			for (int j=i;j<n;j++)
			{
				if (subseq(arr,i,j)==1) count+=1;
				else continue;
			}
		}

		cout<<count<<"\n";

	}
	return 0;
}
