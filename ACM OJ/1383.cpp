#include <iostream>
#include <cstring>
using namespace std;

int w,h,tan;
long long dp[13][2100];
int path[14000][2];

void dfs(int l,int now,int pre){
	if(l>w)return;
	if(l==w)
	{
		path[tan][0]=pre;
		path[tan++][1]=now;
		return ;	
	}
	dfs(l+2,(now<<2)|3,(pre<<2)|3);
	dfs(l+1,(now<<1)|1,pre<<1);
	dfs(l+1,now<<1,(pre<<1)|1);
}

int main(){
	while(1){	
		cin>>h>>w;
		if(!h && !w)break;
		
		if(h<w){
			int t=h;h=w;w=t;
		}
		
		tan=0;
		dfs(0,0,0);
		memset(dp,0,sizeof(dp));
		dp[0][(1<<w)-1]=1;
		for(int i=0;i<h;++i){		
			for(int j=0;j<tan;++j){			
				dp[i+1][path[j][1]]+=dp[i][path[j][0]];
			}
		}
		cout<<dp[h][(1<<w)-1]<<endl;
	}
	return 0;
}

