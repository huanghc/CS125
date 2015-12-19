#include<iostream>
using namespace std;
int main(){
	long n,t,i,sum;
	cin>>n>>t;sum=n;
	long empty[t];
	bool flag=true;
	
	for (i=0;i<t;++i){
		empty[i]=0;
		cin>>empty[i];
	}
	
	for (i=0;i<t;++i){
		long a=n/empty[i];
		if (a==0){
			flag=false;break;
		}
		n=n-a*empty[i]+a;
		sum+=a;
	}
    
	while (n>=empty[t-1] && flag){
		n=n-empty[t-1]+1;
		++sum;
	}
	cout<<sum<<"\t"<<n;
	return 0;
}
