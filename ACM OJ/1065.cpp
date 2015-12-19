#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int dp[1010][1010];  
int main(){	
	memset(dp,0,sizeof(dp));
	char str1[1010];
	char str2[1010];
	int i, j, k=0;
    cin.getline(str1,1010);
    cin.getline(str2,1010);
 
    int len1 = strlen(str1);
    int len2 = strlen(str2);
 
    for(i=1; i<=len1; ++i){  
        for(j=1; j<=len2; ++j){      
            if(str1[i-1] == str2[j-1]){           
                dp[i][j] = dp[i-1][j-1] + 1;
            }
			else if(dp[i][j-1] > dp[i-1][j]){           
                dp[i][j] = dp[i][j-1];
            }
			else{           
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[len1][len2];
}
