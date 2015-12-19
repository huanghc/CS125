#include<iostream> 
#include<cstring>
using namespace std; 
int main(){
	char s1[21000],s2[21000]; 
	int a[21000],b[21000],c[50000],p,i; 
	
	cin.getline(s1,21000,'\n');
	cin.getline(s2,21000,'\n');
	a[0]=strlen(s1); 
	for(i=1;i<=a[0];++i) a[i]=s1[a[0]-i]-'0';
	b[0]=strlen(s2); 
	for(i=1;i<=b[0];++i) b[i]=s2[b[0]-i]-'0';
	p=a[0]+b[0];
	for(i=1;i<=p;++i){
		for(int j=1;j<i+1;++j){
			c[i]+=a[j]*b[i+1-j];
			c[i+1]+=c[i]/10;
			c[i]%=10;			
		}
	}

	while((c[p]==0)&&(p>1)) --p;
	for(i=1;i<=p;++i) cout<<c[p+1-i]; 	 
} 
