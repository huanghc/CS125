#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,k,i,max,front=0,end=0,tmp=0;
	int num[200000];
	int get[200000]={0};
	cin>>n>>k;
	
	for(i=0;i<n;++i){
		scanf("%d", &num[i]);
	}
	for (i=n;i<k+n-1;++i){
		num[i]=num[i-n];
	}
	max=num[0];

	for (i=0;i<k;++i){
		if (num[i]>max){
			max=num[i];tmp=i;
		}
	}
	get[0]=max;
	for (int t=tmp+1;t<k;++t){
		for (int j=end;j>front;--j){
			if (num[t]>get[j]){
				--end;
			}
			else break;
		}
		++end;get[end]=num[t];
	}

	for (i=k;i<n+k-1;++i){
		if (num[i-k]==get[front]){
			++front;
		}
		for (int j=end;j>=front;--j){
			if (num[i]>get[j]){
				--end;
			}
			else break;
		}
		++end;get[end]=num[i];
		
		if (get[front]<max){
			max=get[front];
		}	
//		for (int j=front;j<=end;++j){
//			cout<<i<<": "<<get[j]<<endl;
//		}
	}
	cout<<max;
} 

