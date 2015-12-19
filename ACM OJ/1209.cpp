#include <iostream>
using namespace std;
int main(){
	long long n,i,ans=0;cin>>n;
	long long num;
	for(i=0;i<n;++i){
		cin>>num;
		while(num){
			if (num%2!=0){
				++ans;
			}
			num/=2;
		}
	}
	cout<<ans; 
	
} 
