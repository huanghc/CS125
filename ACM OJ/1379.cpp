#include<iostream>
using namespace std;
int main(){
	int n,i,j,sum=0,ans=0;
	int len[4100];
	cin>>n;
	for (i=0;i<n;++i){
		cin>>len[i];sum+=len[i];
		len[i+n]=len[i];
	}
	
	for(i=0;i<n;++i){
		int tmpsum=0;
		for(j=i;j<n;++j){
			tmpsum+=len[j];
			if(tmpsum*2!=sum) continue;
			else{
				int ls=len[i],rs=len[j+1];
				int ll=i+1,lr=j+2;
				while(1){
					if(ls==rs){//cout<<"i: "<<i<<" j: "<<j<<" ll: "<<ll<<" lr: "<<lr<<endl;
						if ((lr-n>=0 && lr-n<i) || (ll-n>=0 && ll-n<i)) {
							if(ll==j) break;
							if(lr==i+n-1) break;
							ls+=len[ll];++ll;
						}
						else{
							++ans;
							if(ll>=j) break;
							if(lr>=i+n-1) break;
							ls+=len[ll];++ll;
						}
					}
					if(ls<rs){
						if(ll>=j) break;
						ls+=len[ll];++ll;
					}
					if(ls>rs){
						if(lr>=i+n-1) break;
						rs+=len[lr];++lr;
					}					
				}
			}
		}
	}
	cout<<ans;
}
