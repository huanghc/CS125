#include <iostream>
#include <stdio.h>
using namespace std;
double num[1010][1010];
 
int main(){
    int n,x,y,i,j;
    cin>>n;
 
    for (i=1; i<=n; ++i){
        for (j=1; j <=n; ++j){
            num[i][j] = 0.0;
            
			for (x=1; x<=6 ; ++x){
                    for (y=1; y<= 6; ++y){
                        if(i-x>=1 && j-y>=1){
                        	num[i][j] += num[i-x][j-y]/36;
						}                           
                    }
                }
            num[i][j]+=1.0;
        }
    }
    printf("%.2f\n", num[n][n]);
 
    return 0;
}
