#include <iostream>
using namespace std;

int main()
{
	int t;cin>>t;int r,c;
	for (int j=0;j<t;j++)
	{
		cin>>r>>c;int row[64];int col[64];
		row[0]=r;col[0]=c;int i=1;
		while (r<8 && c<8)
		{
			r++;c++;
			row[i]=r;col[i]=c;
			i++;
		}
		r--;c--;row[i]=r;col[i]=c;i++;
		r--;c++;row[i]=r;col[i]=c;i++;

		while(r>1)
		{
			r--;c--;row[i]=r;col[i]=c;i++;
		}

		r++;c++;row[i]=r;col[i]=c;i++;
		r--;c++;row[i]=r;col[i]=c;i++;

		while (r<8 && c<8)
		{
			r++;c++;
			row[i]=r;col[i]=c;
			i++;
		}

		r--;c--;row[i]=r;col[i]=c;i++;
		r--;c++;row[i]=r;col[i]=c;i++;
		while(r>1)
		{
			r--;c--;row[i]=r;col[i]=c;i++;
		}

		while (c>1 && r<8)
		{
			r++;c--;row[i]=r;col[i]=c;i++;
		}		

		r++;c++;row[i]=r;col[i]=c;i++;
		r--;c++;row[i]=r;col[i]=c;i++;
		r++;c++;row[i]=r;col[i]=c;i++;
		while (c>1)
		{
			r--;c--;row[i]=r;col[i]=c;i++;
		}
		r--;c++;row[i]=r;col[i]=c;i++;
		r--;c--;row[i]=r;col[i]=c;i++;
		while (r<8)
		{
			r++;c++;row[i]=r;col[i]=c;i++;
		}

		cout<<i<<endl;
		for (int k=0;k<i;k++)
		{
			cout<<row[k]<<" "<<col[k]<<endl;
		}

	}

	return 0;
}