#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[1000];
	int i,l,j,sum=0;
	cin.getline(s,1000);
	l=strlen(s);
	for (i=0;i<l;++i){
		if (s[i]==' ') continue;
		for (j='A';j<'A'+26;++j){
			if (s[i]==j){
				sum+=(i+1)*(s[i]-'A'+1);continue;
			}
		}	
		for (j='a';j<'a'+26;++j){
			if (s[i]==j){
				sum+=(i+1)*(s[i]-'a'+27);continue;
			}
		}			
	}
	cout<<sum;
} 
