#include <iostream>
#include<cstring>
#include <cstdio>
using namespace std;
 
long count[500000]={0};
 
int main(){
	int n,a,b,i;
	scanf("%d%d%d", &n, &a, &b);
    
	count[a]=1;
      
	if (b%a==0) count[b]=2;
	else count[b]=1; 
 
	for (i=b+1;i<=n;++i){
		count[i]=count[i-a]+count[i-b];
	} 
	
	printf("%d", count[n]);
}
