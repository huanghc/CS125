#include<iostream>
#include <cstring>
using namespace std;
 
int main(){
	int n,i;cin>>n;
	for (i=0;i<n;++i){
		int num[4][4]={0};
		int j=0,k=0,flag=0;
		for (j=0;j<4;++j){
			for (k=0;k<4;++k){
				char tmp;
				cin>>tmp;
				if (tmp=='X') num[j][k]=1;
				if (tmp=='O') num[j][k]=2;
				if (tmp=='T') num[j][k]=0;
				if (tmp=='.') {
					num[j][k]=-1;flag=1;
				}
			}
		}
						
		for (j=0;j<4 && flag!=-1;++j){
			int t=num[j][0];
			bool flag2=true;
			for (k=1;k<4;++k){
				if (!flag2 && num[j][k]==0) break;
				if (t==0){
					if (num[j][k]==0) break;
					t=num[j][k];flag2=false;
					continue;
				}
				if (num[j][k]==0){
					flag2=false;continue;
				}
				if (num[j][k]!=t) break;
			} 
			if (k==4){
				if (t==1){
					cout<<"X won"<< endl;flag=-1;
				}
				if (t==2){
					cout<<"O won"<< endl;flag=-1;
				}
			}
		}
		
		for (j=0;j<4 && flag!=-1;++j){
			int t=num[0][j];bool flag2=true;
			for (k=1;k<4;++k){
				if (!flag2 && num[k][j]==0) break;
				if (t==0){
					if (num[k][j]==0) break;
					t=num[k][j];flag2=false;
					continue;
				}
				if (num[k][j]==0){
					flag2=false;continue;
				}
				if (num[k][j]!=t) break;
			} 
			if (k==4){
				if (t==1){
					cout<<"X won"<< endl;flag=-1;
				}
				if (t==2){
					cout<<"O won"<< endl;flag=-1;
				}
			}
		}
		
		if (flag!=-1){
			int t=num[0][0];bool flag2=true;
			for (k=1;k<4;++k){
				if (!flag2 && num[k][k]==0) break;
				if (t==0){
					if (num[k][k]==0) break;
					t=num[k][k];flag2=false;
					continue;
				}
				if (num[k][k]==0){
					flag2=false;continue;
				}
				if (num[k][k]!=t) break;
			} 
			if (k==4){
				if (t==1){
					cout<<"X won"<< endl;flag=-1;
				}
				if (t==2){
					cout<<"O won"<< endl;flag=-1;
				}
			}
		}
		if (flag!=-1){
			int t=num[0][3];bool flag2=true;
			for (k=1;k<4;++k){
				if (!flag2 && num[k][3-k]==0) break;
				if (t==0){
					if (num[k][3-k]==0) break;
					t=num[k][3-k];flag2=false;
					continue;
				}
				if (num[k][3-k]==0){
					flag2=false;continue;
				}
				if (num[k][3-k]!=t) break;
			} 
			if (k==4){
				if (t==1){
					cout<<"X won"<< endl;flag=-1;
				}
				if (t==2){
					cout<<"O won"<< endl;flag=-1;
				}
			}
		}
		
		if (flag==-1) continue;
		if (flag==1) {
			cout<<"Game has not completed"<< endl;
		}
		else {
			cout<<"Draw"<< endl;
		}	
	}
}
