#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t;cin>>t;
	long long num[100010]={0};
	long long ans=0;
	for (int i=0;i<t;++i){
		cin>>num[i];
	}
	sort(num,num+t);
	for (int i=0;i<t;++i){
		ans=ans+num[i]*(-t+1+2*i);
	}
	cout<<(ans%1000000007);
}
