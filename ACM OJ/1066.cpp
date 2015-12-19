#include <iostream>
#include <cstring>

using namespace std;
int n,m,i,j;
char name[2001];
int cost[26]={0};
int st[2001][2001];

int get(int lh,int rh);

int main(){
	cin>>n>>m;
	char k;cin.get(k);	
	cin.getline(name,m+1);
    for (i=0;i<m;++i){
    	for (j=0;j<m;++j){
    		st[i][j]=-1;
		}
	}
	for(i=0;i<n;++i){
		char t;
		cin>>t;int tmp=t-'a';
		for (j=0;j<26;++j){
			int p,q;
			if((tmp)==j){
				cin>>p>>q;
				if (p>q) cost[tmp]=q;
				else cost[tmp]=p;
			}  
		}
	}
    
	cout<<get(0,m-1);
//	for (i=0;i<m;++i){
//    	for (j=0;j<m;++j){
//    		cout<<st[i][j]<<endl;
//		}
//	}
}

int get(int lh,int rh){
	if (lh>=rh) return 0;
	if (name[lh]==name[rh]) return get(lh+1,rh-1);
	if (st[lh][rh]>=0) return st[lh][rh];

	int mon1=get(lh+1,rh)+cost[name[lh]-'a'];
	int mon2=get(lh,rh-1)+cost[name[rh]-'a'];
	
	if (mon2>mon1) {
		st[lh][rh]=mon1; return mon1;
	}
	else {
		st[lh][rh]=mon2; return mon2;
	}
}
