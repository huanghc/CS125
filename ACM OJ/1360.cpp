#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
struct hourT{
	int start,end;
};
bool cmp(const hourT &m,const hourT &n);
int main(){
	int N,i,j,s=1,tmp1,tmp2;
	cin>>N;
    bool flag=true;
	
	hourT hour[100000];
	for (i=0;i<N;++i){
		cin>>hour[i].start>>hour[i].end;
	}
    sort(hour,hour+N,cmp);
	int c = hour[0].start;
	int d = hour[0].end;
	
    for (i=1;i<N;++i){
		if (hour[i].start>=d){
			++s;
			d=hour[i].end;
	    }
		if (hour[i].end<d){
			d=hour[i].end;
		}
	}
	cout<<s;
}
bool cmp(const hourT &m,const hourT &n){
	return m.start < n.start;
}
