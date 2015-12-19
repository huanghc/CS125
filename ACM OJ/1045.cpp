#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,ans=1;cin>>n;
	int fa[200010] = {0};
	bool exist[200010] = {0};
	int son[200010]={0};
    for (int i=0; i<n; ++i){
        char k;
        k = getchar();
        while(k!='B' && k!='D'){
            k = getchar();
        }
        while (k != 'B' &&  k != 'D') 
            scanf("%c",&k);
		int x,y;   
        if (k=='B'){      	
			scanf("%d %d",&x,&y);
			if(!exist[x]) son[x] = 0;
			fa[y] = x; 
			exist[x] = exist[y] = 1;
			son[x]++;
		}
		if (k=='D'){
            scanf("%d",&x);
            exist[x] = 0;
            if(!exist[fa[x]]) ans--;
            else son[fa[x]]--;
            ans += son[x];
            printf("%d\n", ans);			
		}
    }
    return 0;
}
