#include <iostream>  
using namespace std;  
int n;            
int cost[16][16];  
int dp[16][32768]; 
int num_of_1(int status);
int get(int cur,int status);
 
int main(){   
    int i,j,min;  
    cin>>n;  
    if (n==1){        
        cout<<0<<endl;  
        return 0;  
    }  
    for(i=0;i<n;++i){        
        for(j=0;j<n;++j){            
            cin>>cost[i][j];  
        }  
    }  
    for (i=0;i<n;++i){       
        for (j=0;j<32768;++j){            
            dp[i][j]=-1;  
        }  
    }  
    dp[0][1]=0;     
    min=10000000;  
    for (i=1;i<n;++i){        
        if (cost[0][i]+get(i,(1<<n)-1)<min)   min=cost[0][i]+get(i,(1<<n)-1);  
    }  
    cout<<min<<endl;  
} 
                   
int num_of_1(int status){        
    int i,sum=0;  
    int t=1;  
    for(i=0;i<n;++i){       
        if(status&t)  ++sum;  
        t<<=1;  
    }  
    return sum;  
}  
int get(int cur,int status){    
    if(dp[cur][status]!=-1)  return dp[cur][status];  
    if (num_of_1(status)>2) {          
        int i,t=2;  
        int min=10000000;  
        for (i=1;i<n;++i,t<<=1){           
            if (i==cur)  continue;  
            if (status & t){               
                if (get(i,status & (~(1<<cur)))+cost[cur][i] < min){                      
                    min=get(i,status & (~(1<<cur)))+cost[cur][i];  
                }  
            }  
        }  
        return dp[cur][status]=min;  
    }
	else  return dp[cur][status]=cost[0][cur];                        
}  
 

