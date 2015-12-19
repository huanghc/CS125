#include <iostream>
using namespace std;
	
int main(){
	int L,W,M,N,total=0,i,j,k;
	cin>>L>>W;
	int field[L][W];
	
	for (int i=0;i<L;++i){
		for (int j=0;j<W;++j){
			cin>>field[i][j];
		}
	}
	cin>>M>>N;

	int sum[W];
    for (i=0;i<W;++i){
	    sum[i]=0;
    	for (j=0;j<M;++j){   		
    		sum[i]=sum[i]+field[j][i];
		}
	}

    for (i=0;i<L-M+1;++i){
    	int a=0;
    	for (j=0;j<N;++j){
    		a+=sum[j];
		}
		if (total<a) total=a;
		for(k=1;k<W-N+1;++k){
			a=a-sum[k-1]+sum[k+N-1];
		    if (total<a) total=a;	
		}
		for (k=0;k<W;++k){
			sum[k]=sum[k]-field[i][k]+field[i+M][k];
		}
	}
	cout<<total;
}
    

