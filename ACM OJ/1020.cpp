#include <iostream>
#include <cmath>
using namespace std;

int prime(long long n){
	int i;
	if (n%2==0) return 2;
	for (i=3; i<=sqrt(n);i=i+2){	
		if (n%i==0) return i;
	}
	return n;
}

int main(){
	long long n;
	cin>>n;cout<<n<<"=";
	int num[50000]={0};
	int prim[50000]={0};
	int index=0;
	while (n>1){
		int t=prime(n);//cout<<t<<endl;
		n=n/t;//cout<<n;
		if (index==0){
			prim[index]=t;++num[index];++index;
			continue;
		}
		if (t>prim[index-1]){
			prim[index]=t;++num[index];++index;
		}
		else {
			++num[index-1];
		}	
	}

	for (int i=0;i<index;++i){
		cout<<prim[i]<<"("<<num[i]<<")";
	}	
}
