#include <iostream>
using namespace std;
string add(string s1, string s2){
   int len1=s1.length(),len2=s2.length();
	int p,i; 

	if (len1>len2) p=len1;
	else p=len2;
	int a[p+1],b[p+1];
	string s3;	
	
	for (i=0;i<len1;++i) a[i]=s1[len1-1-i]-'0';
	for (i=len1;i<p+1;++i) a[i]=0;
	for (i=0;i<len2;++i) b[i]=s2[len2-1-i]-'0';
	for (i=len2;i<p+1;++i) b[i]=0;
		
	for(i=0;i<p;++i){
		a[i]+=b[i]; 
		a[i+1]+=a[i]/10;
		a[i]%=10; 
	} 
    p=p+1;
	while((a[p-1]==0)&&(p>1)) --p; 
	for(i=0;i<p;++i){
		char tmp=a[p-1-i]+'0';s3+=tmp;
	}
	return s3;
}

int main(){
	int n;cin>>n;
	string num1[10010];  //11
	string num2[10010];  //10
	string num3[10010];  //01
	string num4[10010];  //00
    num1[2]="1";num2[2]="1";num3[2]="1";num4[2]="1";
	for (int i=3;i<=n;++i){
		num1[i]=add(num1[i-1],num3[i-1]);
		num2[i]=add(num1[i-1],num3[i-1]);
		num3[i]=add(num2[i-1],num4[i-1]);
		num4[i]=num2[i-1];
	}
	cout<<add(add(num1[n],num2[n]),add(num3[n],num4[n]));
}
