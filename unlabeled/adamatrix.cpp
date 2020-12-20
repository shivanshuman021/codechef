#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printmatrix(vector<vector<int>>&mat)
{
    for (int i=1;i<mat.size();++i)
    {
        for (int j=1;j<mat[i].size();++j)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void transpose(vector<vector<int>> &mat, int l)
{
    int temp;
    for (int i=1;i<=l;++i)
    {
        for (int j=i+1;j<=l;++j)
        {
            temp = mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]= temp;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;cin>>t;
	while(t--)
	{
        cin>>n;
        vector<vector<int>> mat(n+1,vector<int>(n+1,0));
        int k;
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                cin>>k;
                mat[i][j] = k;
            }
        }
        int cnt=0;
        
        for (int i=1;i<n;++i)
        {
            if ((mat[1][i+1]-mat[1][i]) == n)
            {
                continue;
            }
            else if ((mat[1][i+1]-mat[1][i]) == 1)
            {
                //cout<<"this executed\n";
                continue;
            }
            else
            {
                transpose(mat,i);
                ++cnt;
                //cout<<"i = "<<i<<"\n";
                //printmatrix(mat);
            }
            
        }

        if ((mat[1][2]-mat[1][1])==n)
        {
            ++cnt;
            //transpose(mat,n);
        }
        
        cout<<cnt<<endl;
	}

	return 0;
}