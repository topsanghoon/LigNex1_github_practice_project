#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b;
	cin>>a>>b;

	while(!(a==0&&b==0)){
		if(a>b){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
		cin>>a>>b;
	}
	

	return 0;
}