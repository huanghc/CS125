#include<iostream>
#include<algorithm>
using namespace std; 
long long num[100000]; 
 
int main(){
	long long N,S,i,j,count=0;	
	cin>>N>>S;
	long long tmp=N-1;
	for (i=0;i<N;++i){
		cin>>num[i];
	}
	sort(num,num+N);
	for (i=0;i<N-1;++i){
		if (num[i]+num[i+1]>S) break;
		for (j=tmp;j>i;--j){
			if (num[i]+num[j]<=S){
				tmp=j;
				count+=(j-i);  //cout<<count<<endl;
				break;
			}
		}
	}
	cout<<count;
}
