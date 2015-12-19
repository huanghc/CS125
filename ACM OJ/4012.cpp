#include<iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
	return a>b;
}
void Insertsort(int a[], int n,int tmp){
	int i, j, k;
	for (i = 0; i < n; i++){	
		if (tmp > a[i])
			break;
	}
	for (k = n-1;k >i; --k){
		a[k] = a[k-1];
	}
	
	a[i ] = tmp;
}


int main(){
	int n,i;
	long long ans=0;
	cin>>n;
	int num[10010];
	for (i=0;i<n;++i){
		cin>>num[i];
	}	
	sort(num,num+n,compare);

	while(n>1){	
		ans+=(num[n-1]+num[n-2]);//cout<<ans<<" ";		
		int tmp=num[n-1]+num[n-2];//cout<<tmp<<endl;
		Insertsort(num, n,tmp);
		--n;
	}
	cout<<ans;	
}
