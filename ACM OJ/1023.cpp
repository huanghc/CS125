#include <iostream>
using namespace std;
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;++i){
		int a=0,s=0;
		cin>>a>>s;
		int sqar[a][a];
		for (int j=0;j<a;++j){
			for (int k=0;k<a;++k){
				cin>>sqar[j][k];
			}			
		}
		if (s==0){
			for (int j=0;j<a;++j){
				for (int k=0;k<a;++k){
					cout<<sqar[j][a-1-k]<<" ";
				}
				cout<<endl;			
			}continue;
		}
		if (s==1){
			for (int j=0;j<a;++j){
				for (int k=0;k<a;++k){
					cout<<sqar[a-1-j][k]<<" ";
				}
				cout<<endl;				
			}continue;
		}
		if (s==2){
			for (int j=0;j<a;++j){
				for (int k=0;k<a;++k){
					cout<<sqar[k][j]<<" ";
				}
				cout<<endl;				
			}continue;
		}		
	}
	return 0;	
}
