#include<iostream>
using namespace std;
int main(){ 
    int n,i,j;
    cin>>n;
    int tri[n][n];

    for(i=0;i<n;++i){
    	for(j=0;j<=i;++j){
    		cin>>tri[i][j];
		}            
	}
        
    for(i=n-2;i>=0;--i){
    	for(j=0;j<=i;++j){
    		if (tri[i+1][j]<tri[i+1][j+1]) tri[i][j]+=tri[i+1][j+1];
    		else tri[i][j]+=tri[i+1][j];
		}            
	}       
    cout<<tri[0][0];
    return 0;
}
