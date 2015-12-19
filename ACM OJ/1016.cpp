#include<iostream> 
#include<cstring>
using namespace std; 
void sub(char s1[],char s2[]);
int main(){
	char s1[500],s2[500],part_s1[500]={0};
	int ans[500]={0}; 
	int i,m,n,k=0; 

	cin.getline(s1,500,'\n');
	cin.getline(s2,500,'\n');
	m=strlen(s1); 
	n=strlen(s2); 

	for (i=0; i<n; i++) part_s1[i]=s1[i];
    part_s1[n]='\0';
    int len=n;int len0=n; 
    
    while (1){  	
    	if (strlen(part_s1)<n || (strlen(part_s1)==n && strcmp(part_s1,s2)<0)){   		
	        part_s1[len]=s1[len0];part_s1[len+1]='\0';
			++len;++len0;    
		}
			
		while(strlen(part_s1)>n || (strlen(part_s1)==n && strcmp(part_s1,s2)>=0)){
			sub(part_s1,s2);
			++ans[k];
		}
		
		if (part_s1[0]=='0') len=0;
		else len=strlen(part_s1);		
		++k;		
		if (len0==m) break;		
	}
	for (i=0;i<k;++i) cout<<ans[i];	 	
}

void sub(char s1[],char s2[]){
	int m=strlen(s1); 
	int n=strlen(s2); 
	int a[500]={0},b[500]={0},i;

	for(i=0;i<m;++i) a[i]=s1[m-1-i]-'0';
	for(i=0;i<n;++i) b[i]=s2[n-1-i]-'0';
	
	for(i=0;i<m;++i){
		a[i]-=b[i]; 
		if (a[i]<0){
			a[i]=10+a[i];
			--a[i+1];
		}
	}
	while (a[m-1]==0 && m>1) --m;
	for(i=0;i<m;++i) {
		s1[i]=a[m-1-i]+'0';
	}
    s1[m]='\0';
}
