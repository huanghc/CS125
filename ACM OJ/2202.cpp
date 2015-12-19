#include <iostream>
#include <stack>
#include <cstdio>
#include <string.h>
using namespace std;
 
struct Point{
    int x;
    int y;
    int done;
    Point(int a,int b){
        x = a;
        y = b;
        done = 0;
    }
};
 
int main(){
	bool map[1005][1005];
	bool vis[1005][1005];	
	int dx[4] = {0,0,-1,+1};
	int dy[4] = {+1,-1,0,0};  		
	int k,n,m;cin>>k;
    for (int i=0; i<k; ++i){ 
        cin>>n>>m;
	    for (int i = 1; i <= n; ++i)
	        for (int j = 1; j <= m; ++j)
	            cin>>map[i][j];

	    memset(vis,0,sizeof(vis));
	    stack<Point> s;
	    Point start(1,1);
	    s.push(start);
	    bool flag=true;
	    while(!s.empty() && flag){
	        Point cur = s.top();
	        s.pop();
	        vis[cur.x][cur.y] = true;
	        for (int i = 0; i < 4; ++i){	        
	            int new_x = cur.x + dx[i];
	            int new_y = cur.y + dy[i];
	            if(new_x>=1 and new_x<=n and new_y>=1 and new_y<=m){
	                if(vis[new_x][new_y]) continue;
	                vis[new_x][new_y] = true;
	                if(map[new_x][new_y]==false or cur.done <= 1){
	                    Point next(new_x,new_y);
	                    next.done = cur.done+map[new_x][new_y];
	                    if(next.done <= 1){
	                        s.push(next);
	                        if(new_x==n and new_y==m){
	                        	cout<<"1\n";flag=false;break;
							}                               
	                    }
	                }
	            }
	        }
	    }
	    if (flag) cout<<"0\n";
    }
    return 0;
}

