#include <iostream>
using namespace std;

long long get[200001];
long long rept[200001];	

int main(){	
	int s,t,i,j,lngst=1,newNum=0;
	long long repeat=0;
	cin>>s>>t;
	
	for(i=s;i<t+3;++i) {
		get[i]=1;
		rept[i]=1;
	}
 
	for(i=s;i<=t;++i){	
		for(j=1;j<=200;++j){		
			if((i*j) % 100==0){
				newNum=i+i*j/100;
				if(newNum>t) break;
				if (get[newNum]<get[i]+1){
					get[newNum]=get[i]+1;
					rept[newNum]=rept[i];
				}
				else if (get[newNum]==get[i]+1){
					rept[newNum]=rept[newNum]+rept[i];
				}
				if (lngst<get[newNum]){
					lngst=get[newNum];		
				}				 				
			}			
		}
	}
	for (i=s;i<=t;++i){
		if (get[i]==lngst) repeat+=rept[i];
	}
	cout<<lngst<<endl<<repeat;
}
