#include <iostream>
using namespace std;
int n,i,j,q;
int num[110]={0};
bool flag=false;

void check(int a,int b);
int main(){	
	cin>>n;
	for (i=0;i<n;++i){
		cin>>num[i];
	}
	
	while(1){
		flag=false;
		for (i=0;i<n;++i){
			for(j=0;j<n;++j){
				check(num[i],num[j]);
			}
		}
		if(!flag) break;	
	}
//	for (i=0;i<n;++i){
//		cout<<num[i]<<" ";
//	}
	cout<<n;	
} 
void check(int a,int b){
	int i,c=0;
	if(a<b){
		int c=a;a=b;b=c;
	}
	q=a/b;//cout<<" "<<a<<" "<<b<<" "<<q<<endl;
	
	for (int i=0;i<n;++i){
		if (num[i]==q) return;
	}
	num[n]=q;++n;flag=true;
}
