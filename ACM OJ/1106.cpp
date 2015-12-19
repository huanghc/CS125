#include <iostream>
using namespace std;
#define MAXL 10
int g[MAXL][MAXL];
int p1[MAXL][MAXL],p2[MAXL][MAXL],p3[MAXL][MAXL];
int b1[MAXL][MAXL],b2[MAXL][MAXL],b3[MAXL][MAXL];

int error,tot;
void init();
void dfs(int x,int y);
void work();

int main(){
	for(int i=1;i<=9;++i){
    	for (int j=1;j<=9;++j){
    		p1[i][j]=i;
			p2[i][j]=j;
			p3[i][j]=((i-1)/3)*3+((j-1)/3)+1;
		}
	}

    int n;
    cin>>n;
    for (int k=1;k<=n;++k){    
        init();
        if (error){cout<<"No\n";continue;}
        work();
    }
}

void init(){  
	error=0;
    for(int i=1;i<=9;++i){
    	for (int j=1;j<=9;++j){
			b1[i][j]=0; b2[i][j]=0; b3[i][j]=0;
    		cin>>g[i][j];
		}
	}

    for(int i=1;i<=9;++i){
    	for (int j=1;j<=9;++j){
			if(g[i][j]){   
			    int p=p1[i][j],x=g[i][j];
			    if(b1[p][x]) error=1;
			    b1[p][x]=1;
			    
				p=p2[i][j];
			    if(b2[p][x]) error=1;
			    b2[p][x]=1;
			    
				p=p3[i][j];
			    if(b3[p][x]) error=1;
			    b3[p][x]=1;
			}
		}
	}
}

void dfs(int x,int y){
    if(x==10){   
        ++tot;
        if(tot>1) error=1;
        return;
    }
    int xt=x,yt=y+1;
    if(yt>9){++xt;yt=1;}
    if(g[x][y]){dfs(xt,yt);return;}
    
	int c1=p1[x][y],c2=p2[x][y],c3=p3[x][y];
    for (int i=1;i<=9;++i){
    	if(b1[c1][i]+b2[c2][i]+b3[c3][i]==0){	    
	        b1[c1][i]=1;
	        b2[c2][i]=1;
	        b3[c3][i]=1;
	        dfs(xt,yt);
	        if(error) return;
	        b1[c1][i]=0;
	        b2[c2][i]=0;
	        b3[c3][i]=0;
	    }
	}    
}

void work(){
    tot=0;
    dfs(1,1);
    if(tot==0 || error){
    	cout<<"No\n";
	}
    else cout<<"Yes\n";
}


