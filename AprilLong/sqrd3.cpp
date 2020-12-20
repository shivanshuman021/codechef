#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    vector<bool>m;
	    vector<long int>pos;
	    long int n,sum=0;;
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]%2==0)
	        {
	            if(a[i]%4==0)
	            {
	                m.push_back(true);
	                pos.push_back(i);
	            }     
	            else
	            {
	                m.push_back(false);
	                pos.push_back(i);
	            }     
	        }
	    }
	    long int sizevec=pos.size();
	    for(long int i=0;i<sizevec;i++)
	    {
	        if(m[i]==false)
	        {
	            if(i==0&&sizevec!=1)
	            {
	                if(pos[i]==0)
	                {
	                   sum+=pos[i+1]-pos[i];
	                }
	                else{
	                    sum+=(pos[i]+1)*(pos[i+1]-pos[i]);
	                }
	            }
	            else if(i==sizevec-1&&sizevec!=1)
	            {
	                if (pos[i]==n-1)
	                {
	                     sum+=pos[i]-pos[i-1];
	                }
	                else{
	                    sum+=(n-pos[i])*(pos[i]-pos[i-1]);
	                }
	            }
	            else
	            {
	                if(sizevec==1)
	                {
	                    sum+=(pos[i]+1)*(n-pos[i]);
	                }else{
	                sum+=(pos[i+1]-pos[i])*(pos[i]-pos[i-1]);}
	            }
	        }
	    }
	    //cout<<sum<<endl;
	    long long int print=((n*(n+1))/2)-sum;
	    
	    cout<<print<<endl;
	    
	}
	return 0;
}