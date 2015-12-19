#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct Point{
    int x;
    int y;
    int z;
};

int n;
Point points[100010];
int curx[100010];
int cury[100010];


bool cmpPoint(const Point& a,const Point& b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}

int find(int x,int y){
    Point tofind;
    tofind.x = x;
    tofind.y = y;
    Point* f = lower_bound(points,points+n,tofind,cmpPoint);
    if(f != points+n and f->x==x and f->y==y)
        return f->z;
    return 0;
}

int main(){
    cin>>n;
    for (int i = 0; i < n; ++i){
        scanf("%d %d %d",&points[i].x,&points[i].y,&points[i].z);
    }
    
    for (int i = 0; i < 100010; ++i){
    	curx[i]=i;cury[i]=i;
	}
                
    int m;
    cin>>m;
    sort(points,points+n,cmpPoint);
    for (int i = 0; i < m; ++i)
    {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==0){
            swap(curx[x],curx[y]);
        }else if(op==1)
            swap(cury[x],cury[y]);
        else{
            printf("%d\n", find(curx[x],cury[y]));
        }
    }
    return 0;
}
