#include <iostream>
using namespace std;
int knap(int volume,int s);

int main(){
	int volume,s;
	cin>>volume>>s;	
	cout<<knap(volume,s);
}

int knap(int volume,int s){
	int used[volume];used[0]=0;
	int good[s][2];
	for (int i=0;i<s;++i){
		cin>>good[i][0]>>good[i][1];
	}

	for (int v=1;v<volume+1;++v){
		int value=0;
		for (int i=0;i<s;++i){
			if (good[i][0]>v) continue;
			if (used[v-good[i][0]]+good[i][1]>value) 
			value=good[i][1]+used[v-good[i][0]];
		}
		used[v]=value;	
	}
	return used[volume];	
}
