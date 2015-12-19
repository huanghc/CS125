#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n, m;
    scanf("%d%d", &n, &m);
    int score[100000];
    int i,j,k;
    for (i=0;i<n;++i){
    	scanf("%d",score+i);
	}

    for (i=0;i<m;++i){
    	int a,b,count=0;
    	scanf("%d%d", &a, &b);
    	for (j=0;j<n;++j){
    		if (score[j]<a || score[j]>b) continue;
    		++count;
		}
		printf("%d\n", count);
	}	
} 
