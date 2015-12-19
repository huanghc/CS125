#include <iostream>
using namespace std;
int main(){
	int time,sum=0;
	cin>>time;
	int tree[time][2];
 
	for (int i=0;i<time;++i){
		cin>>tree[i][0]>>tree[i][1];
		for (int j=0;j<i;++j){
			if ((tree[i][0]<=tree[j][1] && tree[i][1]>=tree[j][0])
			|| (tree[i][0]<=tree[j][1] && tree[i][1]>=tree[j][0])){
				if (tree[i][0]>tree[j][0]) tree[i][0]=tree[j][0];
				if (tree[i][1]<tree[j][1]) tree[i][1]=tree[j][1];
				tree[j][0]=tree[j][1]=0;
			}
		}
	}
	for (int i=0;i<time;++i){
		sum=sum-tree[i][0]+tree[i][1];
	}
	cout<<sum;
	return 0;
} 
