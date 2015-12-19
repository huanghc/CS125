#include <iostream>
using namespace std;
struct point{
    int x,y,step;
};
int M,N,tmpnum=1;
int p[30][30]={0};
int q[30][30]={0}; 
point now,next;
point allp[1000];

void change(int tmpx,int tmpy);

int main(){
	int M1,M2,i,j,edi,edj,tmp=1;
	cin>>M>>N>>M1>>M2;
	
	for(i=0;i<M;++i){
		for(j=0;j<N;++j){
			cin>>p[i][j];
			q[i][j]=0;
			if (p[i][j]==3){
				q[i][j]=1;
				now.x=i;now.y=j;now.step=0;
				allp[1]=now;
				continue;
			} 
			if (p[i][j]==4){
				edi=i;edj=j;
				continue;
			} 			
		}
	}

	while(tmp<=tmpnum){
		now=allp[tmp];++tmp;
		if ( (now.x==edi) && (now.y==edj) ){ 
			cout<<now.step; return 0; 
		}
		next.step=now.step+1;
		int tmpx;int tmpy;
		tmpx=now.x+M1;tmpy=now.y+M2;
	    change(tmpx,tmpy);
	    tmpx=now.x+M1;tmpy=now.y-M2;
	    change(tmpx,tmpy);
	    tmpx=now.x-M1;tmpy=now.y+M2;
	    change(tmpx,tmpy);
	    tmpx=now.x-M1;tmpy=now.y-M2;
	    change(tmpx,tmpy);
	    tmpx=now.x+M2;tmpy=now.y+M1;
	    change(tmpx,tmpy);
	    tmpx=now.x+M2;tmpy=now.y-M1;
	    change(tmpx,tmpy);
	    tmpx=now.x-M2;tmpy=now.y+M1;
	    change(tmpx,tmpy);
	    tmpx=now.x-M2;tmpy=now.y-M1;
	    change(tmpx,tmpy);				
	}	
	cout<<tmpnum;
}

void change(int tmpx,int tmpy){
	if (tmpx>=0 && tmpx<M && tmpy>=0 && tmpy<N && q[tmpx][tmpy]!=1){
//		if (p[tmpx][tmpy]==4){
//			cout<<next.step;
//			return 0;
//		}
		if (p[tmpx][tmpy]==1 || p[tmpx][tmpy]==4){
			next.x=tmpx;next.y=tmpy;
			++tmpnum;allp[tmpnum]=next;
			q[tmpx][tmpy]=1;
		}
	}
}
