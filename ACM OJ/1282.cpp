#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int num[2015],order[2015];
int value[2015][2015],v2[2015][2015];
bool compare(int a, int b){
	if (a<b) return 1;
	else return 0;
}
int main(){
	int n,i,j;cin>>n;
	
	long long ans=1<<30;
	for(i=1; i<=n ; ++i){
        cin >>num[i];
        order[i]=num[i];
    } 
	sort(order+1,order+n+1);
    for(i=1; i<=n; ++i){   
        for(j=1; j<=n; ++j){        
            value[i][j] = v2[i-1][j] + abs(num[i]-order[j]);
            if(j == 1) v2[i][j] = value[i][j];
            else v2[i][j] = min(value[i][j],v2[i][j-1]);
        }
    }
    for(i=1; i<=n; ++i) {
    	if (ans>value[n][i]) ans=value[n][i];
	}
	sort(order+1,order+n+1,compare);
	for(i=1; i<=n; ++i){   
        for(j=1; j<=n; ++j){        
            value[i][j] = v2[i-1][j] + abs(num[i]-order[j]);
            if(j == 1) v2[i][j] = value[i][j];
            else v2[i][j] = min(value[i][j],v2[i][j-1]);
        }
    }
    for(i=1; i<=n; ++i) {
    	if (ans>value[n][i]) ans=value[n][i];
	}
    cout<<ans;
}
