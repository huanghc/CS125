#include <iostream>
#include<cstring>

using namespace std;
void mul(char s1[],int s2);
void div(char s1[],int s);

int main(){
	int i,n,j;
	cin>>n;
	int a, b;
	a = n-(n/2) + 1;
	b = 1;
	char s[5000];
	s[0]=1+'0';s[1]='\0';
    for (i=0;i<=(n/2)-1;++i){
	    mul(s,a);
		div(s,b);
		++a;++b;
	} 
	cout<<s;
} 

void mul(char s1[],int s2){
	int a[5000]={0}, c[5000]={0}; 
    int i,k,d=0,b; 
    b=s2;
    k=strlen(s1); 
    for(i=0;i<k;++i) a[i]=s1[k-i-1]-'0'; 
    
    for(i=0;i<=k+6;++i) {   
        c[i]=(a[i]*b+d)%10;
        d=(a[i]*b+d-c[i])/10; 
    }

    while(c[k+6]==0 && k>-5) k--; 
    for(i=k+6;i>=0;--i) s1[k+6-i]=c[i]+'0'; 
	s1[k+7]='\0';	
}

void div(char s1[],int s2){
	int a[5000] = {0}, c[5000] = {0}; 
    int i,k,d=0,b; 
    b=s2;
    k=strlen(s1); 
    for(i=0;i<k;++i) a[i]=s1[k-i-1]-'0'; 
    
    for(i=k-1;i>=0;--i) {   
        d=d*10+a[i]; 
        c[i]=d/b;
        d=d % b; 
    }
    while(c[k-1]==0 && k>1) k--; 
    for(i=k-1;i>=0;i--) s1[k-1-i]=c[i]+'0'; 
	s1[k]='\0';	
}


