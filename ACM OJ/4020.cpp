#include <iostream>
#include <algorithm>
using namespace std;
int num[1010] , dp[1010][1010];

int main(){
    int n,i,j,ans=0;cin>>n;
    for(i=1;i<=n;i++){
		cin>>num[i];
	}
    for(i=1;i<=n;i++){
    	for(j=0;j<=i;j++){
            if( num[i]==i-j ) dp[i][j]=dp[i-1][j] + 1;
            dp[i][j]=max(max(dp[i][j] ,dp[i-1][j]) ,dp[i-1][j-1]); 
        }
	}

    for(int i=0;i<=n;i++){
    	if (ans<dp[n][i]) ans=dp[n][i];
	}       
    cout<<ans;
    return 0;
}
