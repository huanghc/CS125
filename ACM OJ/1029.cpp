#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int line,t=1;
	cin>>line;
	char p[line+1][10000];
	int change[line][2];

	for(int i=0;i<(line+1);++i){
		cin.getline(p[i],10000,'\n');		
	}

	for (int j=0;j<(line-1);++j){
		for (int k=0;k<2;++k){
			cin>>change[j][k];			
		}
		strcat(p[change[j][1]],"\t");
		strcat(p[change[j][1]],p[change[j][0]]);
		t=change[j][1];
	}
	cout<<p[t];
}

