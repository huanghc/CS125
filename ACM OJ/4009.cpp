#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s1[100],s2[100];
	int i,j,k,l;
	cin.getline(s1,100);
	cin.getline(s2,100);
	l=strlen(s1);
	
	for (i=2;i<=l/2;++i){
		if (l%i!=0) continue;
		int a=l/i,n=0;bool flag=true;
		for (j=0;j<a;++j){
			for (k=0;k<i;++k){
				if(s2[n]!=s1[j+a*k]) {
					flag=false;break;
				}
				++n;
			}
			if (!flag)	break;	
		}
		if (n==l) {
			cout<<a;return 0;	
		}
	}
	cout<<"No Solution";
} 
