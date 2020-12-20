#include <cstdio>

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


void output(unsigned long long int b[],int size)
{
    unsigned long long int ones=0;unsigned int even_1s=0,odd_1s=0;bit v;

    for (int i=0;i<size;i++)
    {
        ones = v.countSetBits(b[i]);
        
        if (ones%2==0) even_1s++;
        else odd_1s++;
    }

	printf("%u ",even_1s);
	printf("%u \n",odd_1s);
}


int main()
{
	/*ios_base::sync_with_stdio(false); 
    cin.tie(NULL);*/

    unsigned int T;
    scanf("%u",&T);
    int n,q;
    int p;

    for (int i=0;i<T;i++)
    {
    	scanf("%d %d",&n,&q);
    
    	unsigned long long int a[n];
    	for (int k=0;k<n;k++)
    	{
    		scanf("%llu",&a[k]);
    	}
    	
    	unsigned long long int b[n];
    	for (int k=0;k<q;k++)
    	{
    		scanf("%d",&p);
    		for (int j=0;j<n;j++)
    		{
                unsigned long long int l = p^a[j];
    			b[j]=bin(l);	
       		}
    		output(b,n);
    	}
    }
    return 0;
}