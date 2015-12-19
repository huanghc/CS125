#include <iostream>
using namespace std;

int input[16][16];
int now[16];
int next[16];
int front[16];
int main(){
    int n,m,min=1000;
    
    cin>>n>>m;
    for (int i = 0;i < n;++i) 
        for (int j = 0;j < m;++j) cin>>input[i][j];

    if (n==1){
        int i,cnt = 0;
        for (i = 0;i < m;++i) if (input[0][i] & 1){
            if (i+1 < m) input[0][i+1]++;
            if (i+2 < m) input[0][i+2]++;
            cnt++;
        }
        if (input[0][m-1] & 1) cout<<-1<<endl;
        else cout<<cnt<<endl;
        return 0;
    }
    
    for (int i = 0;i < 1<<m;++i){
	      
        for (int j = 0;j < m;++j) { 
             now[j] = input[0][j];
             next[j] = input[1][j];
        }
        int t = 1,cnt = 0;
        for (int j = 0;j < m;++j,t<<=1){
             if (i & t){
     			 ++next[j];
                 ++now[j];
                 if (j > 0) ++now[j-1];
                 if (j<m-1) ++now[j+1]; 
                 ++cnt;
			 } 
		}
		for (int j=1;j<n-1;++j){
			for (int k = 0;k < m;++k){
	            front[k] = now[k];
	            now[k] = next[k];
	            next[k] = input[j+1][k];
	        }
	        for (int k = 0;k < m;++k){
	            if (front[k] & 1){
	                 ++next[k];
	                 ++now[k];
	                 if (k> 0) ++now[k-1];
	                 if (k<m-1) ++now[k+1];
	                 ++cnt;
	            }
	        }
		}
							
        for (int j = 0;j < m;++j) if (now[j] & 1) {
            next[j]++;
            if (j>0) next[j-1]++;
            if (j<m-1) next[j+1]++;
            cnt++;
        }
        bool tmp=true;
        for (int j = 0;j < m;++j){
            if (next[j] & 1) {
                tmp=false;break;
            }
        }
        if (tmp && cnt<min) {min = cnt;}
     }
     
     if (min < 1000) cout<<min;
     else cout<<-1;
    
    return 0;
}
