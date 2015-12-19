#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int i,n,m,tmp=0,first=0;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	n=s1.length();
	m=s2.length();
	if (n!=m) {
		cout<<"NO";
		return 0;
	}
	for (i=0;i<n;++i){
		if (s1[i]!=s2[i]){
			if (tmp==0){
				tmp=1;first=i;
			}
			else if (tmp==1){
				if (s1[first]!=s2[i] || s1[i]!=s2[first]){
					cout<<"NO";return 0;
				}
				else tmp=2;
			}
			else {
				cout<<"NO";return 0;
			}
		}					
	}
	if (tmp==1) cout<<"NO";
	else cout<<"YES";
	return 0;
}
