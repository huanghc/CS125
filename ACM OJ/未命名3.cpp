#include<iostream> 
#include<cstring>
#include<sstream>
using namespace std; 
void add(char s1[],char s2[],char s3[]){
	int a[1000],b[1000],p,i; 

	a[0]=strlen(s1); 
	for(i=1;i<=a[0];++i) a[i]=s1[a[0]-i]-'0';
	b[0]=strlen(s2); 
	for(i=1;i<=b[0];++i) b[i]=s2[b[0]-i]-'0';
	
	if (a[0]>b[0]) p=a[0];
	else p=b[0];
	
	for(i=1;i<=p;++i){
		a[i]+=b[i]; 
		a[i+1]+=a[i]/10;
		a[i]%=10; 
	} 
    p=p+1;
	while((a[p]==0)&&(p>1)) --p; 
	for(i=1;i<p+1;++i) s3[i-1]a[p+1-i]; 
	s3[p+1]='\0'	
}
