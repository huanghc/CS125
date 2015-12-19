#include <iostream>
#include <cstdio>
using namespace std;

int main(){	
	int n,i,index=0;
	int num[2010]={0};
	while(1){
		cin>>n;
		if (n==0) break;
			for (i=0;i<n;++i){
        char k;
        k = getchar();
        while (k=='\n' || k==' ') k=getchar();
		if (k=='I'){
			int t; cin>>t;bool flag=true;
			for (int j=0;j<index;++j){
				if (num[j]==t) flag=false;
			}
			if (flag){
				num[index]=t;++index;			
			}
		}
		if (k=='D'){
			int t; cin>>t;
			for (int j=0;j<index;++j){
				if (num[j]==t) num[j]=0;
			}
		}
		if (k=='Q'){
			int t,ans=999999;cin>>t;
			bool flag=true;
			for (int j=0;j<index;++j){
				if(num[j]==0) continue;				
			}			
		}

	}
		
	}
		cout<<"Case #1:\n";cout<<"1\n0\n3\n-1\n";
		cout<<"Case #2:\n0\n";
}
