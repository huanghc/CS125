#include <iostream>
using namespace std;
int main(){
	int a,i,j; 
	cin>>a;
	char t[a][a],s[a][a];
	for (i=0;i<a;++i) cin>>t[i];
	for (i=0;i<a;++i) cin>>s[i];

	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
			if (t[i][j]!=s[j][a-1-i]) break;
		}
		if (j!=a) break; 
	} 
	if (i==a && j==a){
		cout<<1;return 0;
	} 

	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
			if (t[i][j]!=s[a-1-i][a-1-j]) break;
		}
		if (j!=a) break; 
	}
	if (i==a && j==a){
		cout<<2;return 0;
	} 
	
	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
			if (t[i][j]!=s[a-1-j][i]) break;
		}
		if (j!=a) break; 
	}
	if (i==a && j==a){
		cout<<3;return 0;
	} 
	
	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
			if (t[i][j]!=s[i][a-1-j]) break;
		}
		if (j!=a) break; 
	}
	if (i==a && j==a){
		cout<<4;return 0;
	} 
	
	for (i=0;i<a;++i){
    	for(j=0;j<a;++j){
		    if (t[i][j]!=s[a-1-j][a-1-i]) break;
		}
		if (j!=a) break; 
	}
    if (i==a && j==a){
		cout<<5;return 0;
	} 
	
	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
		    if (t[i][j]!=s[a-1-i][j]) break;
		}
		if (j!=a) break; 
	}
    if (i==a && j==a){
		cout<<5;return 0;
	} 
	
	for (i=0;i<a;++i){
    	for(j=0;j<a;++j){
		    if (t[i][j]!=s[j][i]) break;
		}
		if (j!=a) break; 
	}
    if (i==a && j==a){
		cout<<5;return 0;
	} 
	
	for (i=0;i<a;++i){
		for(j=0;j<a;++j){
			if (t[i][j]!=s[i][j]) break;
		}
		if (j!=a) break; 
	}
    if (i==a && j==a){
		cout<<6;return 0;
	} 
	
	cout<<7;return 0;
}
