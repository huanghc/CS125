#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	long long len=str.length();
	long long i,s=0,t=0,a=0,r=0;
	long long tmpr=0,tmps=0,tmpt=0,tmpa=0;
	for (i=0;i<len;++i){
		if (str[i]=='S'){
			++s;++tmps;
			continue;
		}
		if (str[i]=='T'){
			++t;
			if (tmps>tmpt) ++tmpt;
			continue;
		}
		if (str[i]=='A'){
			++a;
			if (tmpt>tmpa) ++tmpa;
			continue;
		}
		if (str[i]=='R'){
			++r;
			if (tmpa>tmpr){
				++tmpr;
			}
			continue;
		}
	}
	long long dog=s;
	if (s>t) dog=t;
	if (dog>a) dog=a;
	if (dog>r) dog=r;

	cout<<s*t*a*r<<" "<<dog<<" "<<tmpr;
	
}
