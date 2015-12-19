#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int i,n,L,v,len=0;
	int ant[100000];
	int dirct[100000];
	cin>>n>>L>>v;
	for (i=0;i<n;++i){
		cin>>ant[i];
	}
	for (i=0;i<n;++i){
		cin>>dirct[i];
	}
	for (i=0;i<n;++i){
		if (dirct[i]==1 && (L-ant[i])>len) len=L-ant[i];
		if (dirct[i]==0 && ant[i]>len) len=ant[i];
	}
	printf("%.3f\n",double(len)/v);
	
}
