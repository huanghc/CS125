#include <iostream>
#include <cstring>
using namespace std;
char get[103][2003];
void list(int a,int b);
void ins(int a,int b,char c[]);
void del(int a,int b,int d);
 
int main(){
	int line=0,i=0;
	
	while(1){
		cin.getline(get[i],2003,'\n');
		if (strcmp(get[i],"******")==0){
			break;
		}
		++line;++i;
	}
	
	while(1){
		char order[2003];
		int a,b,d;char c[2003];
		cin>>order;
		
		if (order[0]=='l') {
		    cin>>a>>b;
			if (a<1 || b>line || a>b ){
				cout<<"Error!"<<endl;
				continue;
			}
			list(a,b);
		}
		else if (order[0]=='i'){
			cin>>a>>b;
			cin.get(c,2003);
			if (a<1 || a>line || b<1 || b>strlen(get[a-1])+1){
				cout<<"Error!"<<endl;
				continue;
			}	
			ins(a,b,c);
		}
		else if (order[0]=='d'){			
			cin>>a>>b;
			cin>>d;
			if (a<1 || a>line || b<1 || d<0 || b> strlen(get[a-1]) || d+b>strlen(get[a-1])+1){
				cout<<"Error!"<<endl;
			    continue;
			}
			del(a,b,d);
		}
		else if (order[0]=='q') {
			for(i=0;i<line;i++){
				cout<<get[i]<<endl;
			}
			break;
		}
	} 
}
 
void list(int a,int b){
	for (int i=a-1;i<=b-1;++i){
		cout<<get[i]<<endl;
	}
}
 
void ins(int a,int b,char c[]){
	int i,len1=strlen(get[a-1]),len2=strlen(c);
	for (i=len1-1;i>=b-1;--i){
		get[a-1][i+len2-1]=get[a-1][i];
	}
	for (i=1;i<len2;++i){
		get[a-1][b-2+i]=c[i];
	}
}
 
void del(int a,int b,int d){
	int i,len1=strlen(get[a-1]);
	for (i=d+b-1;i<len1;++i){
		get[a-1][i-d]=get[a-1][i];
	} 
	for (i=0;i<d;++i) get[a-1][len1-1-i]=0;
}
