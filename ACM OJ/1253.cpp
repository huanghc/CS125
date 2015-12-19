#include<iostream>
#include <algorithm>
using namespace std;
struct pointT{
	int value;
	int a;
	int b;
};
bool comp(const pointT &a,const pointT &b){
    return a.value>b.value;
}
int main(){
	int m,n,k,i,j,tmp,index=0;cin>>m>>n>>k;
	pointT point[450];
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			cin>>tmp;
			if (tmp>0) {
				point[index].value=tmp;
				point[index].a=i+1;point[index].b=j+1;
				++index;
			}
		}
	}
	sort(point,point+index,comp);
//	for(i=0;i<index;++i){
//		cout<<point[i].a<<point[i].b<<point[i].value<<endl;
//	}
	int ans=0;k=k-point[0].a-1;//cout<<k<<endl;
	for(i=1;i<index;++i){
		if((k-point[i-1].a)<0){
			cout<<ans;return 0;
		}
		else{
			ans+=point[i-1].value;
			k=k-abs(point[i].a-point[i-1].a)-abs(point[i].b-point[i-1].b)-1;
			if (k<0) {
				cout<<ans;return 0;
			}
		}//cout<<"ans: "<<ans<<"k: "<<k<<endl;
	}
	if((k-point[index-1].a)<0){
		cout<<ans;return 0;
	}
	else{
		ans+=point[i-1].value;
	    cout<<ans;return 0;
	}
}
