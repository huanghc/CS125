#include <iostream>
#include<algorithm>
using namespace std;
struct taskT{
	int tim,scor;
};
bool cmp(const taskT &m,const taskT &n);

int main(){
	int n,i,j,sum=0;
	cin>>n;
	taskT task[100010];
	int get[100010]={0}; 
	for (i=0;i<n;++i){
		cin>>task[i].scor>>task[i].tim;
	}

    sort(task,task+n,cmp);  
    for(i=0;i<n;++i){   	
        int t=task[i].tim;
        for (j=t;j>0;--j){
       	    if(get[j]==0){    
               get[j]=1;
               sum+=task[i].scor;
               break;
            } 	
	    }                            
    }         
    cout<<sum;
	return 0;          
}
bool cmp(const taskT &m,const taskT &n){
	return m.scor > n.scor;
}
