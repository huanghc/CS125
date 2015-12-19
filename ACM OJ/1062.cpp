#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int tmp1[1000010] = {0};
int tmp2[1000010] = {0};
int get[1000010]={0};
int main(){
    int n,m=0,i,j=0;
    cin >> n;
    int *robot = new int [n];
    for(i=0;i<n;++i) scanf("%d",robot+i);

    for(i=0;i<1000010;++i) get[i] = 999999999;

    for(i=0;i<n;++i){
       j = lower_bound(get,get+n,robot[i])-get;
       tmp1[i] = j+1;
       get[j] = robot[i];
    }

    j=0;
    for(i=0;i<1000010;++i) get[i] = 999999999;

    for(i=0;i<n;++i){
       j = lower_bound(get,get+n,robot[n-1-i])-get;
       tmp2[n-1-i] = j+1;
       get[j] = robot[n-1-i];
    }

    for(i=0;i<n;++i) {
        if (m<tmp1[i]+tmp2[i]-1) m=tmp1[i]+tmp2[i]-1;
    }
    cout<<n-m;

}

