#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
 
int n,m;
int map[105][105];
bool vis[105][105];
int tmp1[6][6]={0};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1}; 
struct place{
    int x;
    int y;
    int id;
    int step; 
    place(int i=0,int j =0):x(i),y(j){
        step = 0;
        id = 0; 
    }
};
place start;
place boxes[5];

int path[5];
int len = 0;
int bfs(place s, place e);
int build();

int main(){ 
    cin>>n>>m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin>>map[i][j];
            if(map[i][j]==1){
                boxes[len].x = i;
                boxes[len].y = j;
                path[len] = len;
                len++;
            }
            if(map[i][j]==2){
                start.x = i;
                start.y = j;
                start.id = 2;
                start.step = 0; 
            }
        }
    } 
    cout<<build()<<endl; 
    return 0;
}
 

int build(){
	int i,j;
    for (i = 0; i < len; ++i){    
        tmp1[5][i] = bfs(start,boxes[i]);
        if(tmp1[5][i]==-1) return -1;
    }
 
    for (i = 0; i < len; ++i){    
        for (j = i+1; j < len; ++j){      
            tmp1[i][j] = tmp1[j][i] = bfs(boxes[i],boxes[j]);
            if(tmp1[i][j]==-1) return -1;
        }
    }
    int ans = 1<<30;
    do{
        int dis = tmp1[5][path[0]];
        for (i = 1; i < len; ++i){      
            dis += tmp1[path[i]][path[i-1]];
        }
        ans = min(ans,dis);
    }while(next_permutation(path,path+len));
    
	return ans;
}

int bfs(place s, place e){
    queue<place> q;
    memset(vis,false,sizeof(vis));
    s.step = 0;
    q.push(s);
    while(!q.empty()){
        place cur = q.front();
        q.pop();
        vis[cur.x][cur.y] = true;
        place next;
        for (int i=0; i<4; ++i){      
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            if(next.x<1 || next.x>n || next.y<1 || next.y>m) continue;
            if(vis[next.x][next.y])
                continue;
            next.id = map[next.x][next.y];
            vis[next.x][next.y] = true;
            if(next.id != -1){
                next.step = cur.step + 1; 
                if(next.x == e.x and next.y == e.y)
                    return next.step;
                q.push(next);
            }
        }
    }
    return -1; 
}
 
