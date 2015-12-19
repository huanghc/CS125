#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int get[55][55]={0},value[55][55][55][55]={0};
int max(int a,int b){return a>b?a:b;}
int main(){   
    int n,m;
    cin>>n>>m;   
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>get[i][j];
		}           
	}
          
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		 for(int k=1;k<=n;k++){
    		 	for(int l=1;l<=m;l++){
                    value[i][j][k][l]=max(max(value[i-1][j][k-1][l],value[i-1][j][k][l-1]),
                                      max(value[i][j-1][k-1][l],value[i][j-1][k][l-1]))
                    + get[i][j]+get[k][l];
                    if(i==k&&j==l) 
                        value[i][j][k][l]-=get[i][j];
                }
			 }             
		}          
	}
           
    cout<<value[n][m][n][m];
    return 0;
}
