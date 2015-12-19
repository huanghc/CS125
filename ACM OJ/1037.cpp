#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b);
int main(){
	int m,n,i;
	int high[10000],low[10000];
	cin>>n>>m;
	int sum=n,tmp=m-1;
	for (i=0;i<n;++i){
		cin>>high[i];
	}
	for (i=0;i<m;++i){
		cin>>low[i];
	}
	sort(low,low+m);
	sort(high,high+n,cmp);

	for (i=0;i<n;++i){
		if (tmp<0) break;
		for (int j=tmp;j>=0;--j){
			if (high[i]>low[j]){
				++sum;tmp=j-1;
				break;
			}
		}		
	}
	cout<<sum;
} 
bool cmp(int a,int b){
	return a > b;
}

