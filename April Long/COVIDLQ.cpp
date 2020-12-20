#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	int t,n,a;
	cin>>t;
	string s = "";
	for (int i=0;i<t;i++){
		cin>>n;
		for (int j =0;j<n;j++){
			cin>>a;
			s+=a;
		}
		cout<<"string is "<<s<<endl;
	}


	return 0;
}