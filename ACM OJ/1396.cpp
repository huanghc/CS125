#include <iostream>
using namespace std;

int main(){
	int t;cin>>t;	
	for (int i=0;i<t;++i){
		int n;
		long long ans=0;
		cin>>n;
		for (int j=0;j<=n/5;++j){
			int tmp=(n-5*j);
			if (tmp!=1) {
				if (tmp%2==0){
					ans+=(tmp/6+1);
				}
				else ans+=((tmp-3)/6+1);
			}
		}
		cout<<ans<<"\n";
	}
}
