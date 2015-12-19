#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int v[370000];
int main(){
	int n,i;cin>>n;	
	for (i=1;i<370000;++i){
		v[i]=10010;
	}	
	v[0]=0;
	for (i=1;i<=n;++i){
		if(i==1) v[i]=1;
		if(v[int(abs(i-1))]+1<v[i]) v[i]=v[int(abs(i-1))]+1;
		if(v[int(abs(i-2))]+1<v[i]) v[i]=v[int(abs(i-2))]+1;
		if(v[int(abs(i-6))]+1<v[i]) v[i]=v[int(abs(i-6))]+1;
		if(v[int(abs(i-24))]+1<v[i]) v[i]=v[int(abs(i-24))]+1;
		if(v[int(abs(i-120))]+1<v[i]) v[i]=v[int(abs(i-120))]+1;
		if(v[int(abs(i-720))]+1<v[i]) v[i]=v[int(abs(i-720))]+1;
		if(v[int(abs(i-5040))]+1<v[i]) v[i]=v[int(abs(i-5040))]+1;
		if(v[int(abs(i-40320))]+1<v[i]) v[i]=v[int(abs(i-40320))]+1;
		if(v[int(abs(i-362880))]+1<v[i]) v[i]=v[int(abs(i-362880))]+1;
	}
    cout<<v[n];

}
