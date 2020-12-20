#include <iostream>
using namespace std;

class bit { 
    /* Function to get no of set bits in binary 
representation of passed binary no. */
public: 
    unsigned int countSetBits(unsigned long long int n) 
    { 
        unsigned int count = 0; 
        while (n) { 
            n &= (n - 1); 
            count++; 
        } 
        return count; 
    } 
};

unsigned long long int bin(unsigned long long int x)
{
	unsigned long long int no=0;
	int base=1;

	while(x)
	{	
		no+=(base*(x%2));
		base=base*10;
		x = x/2;
	}

	return no;
}

int main()
{
	unsigned long long int arr[5] ;bit v;

	for (int i=0;i<5;i++)
	{
		cin>>arr[i];
	}cout<<endl;

	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for (int i=0;i<5;i++)
	{
		cout<<bin(arr[i])<<" ";
	}cout<<" ";

	int a;
	for (int i=0;i<5;i++)
	{
		a = __builtin_popcount(arr[i]);
		cout<<a<<" ";
	}
	cout<<endl;

	
	return 0;
}