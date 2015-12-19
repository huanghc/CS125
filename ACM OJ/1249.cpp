#include <iostream>
using namespace std;
int check(int a,int b);
int number[10000][2],s=0;
void bubble(int s);

int main(){
	int n,i,j;
	cin>>n;

	for (j=1;j<=n;++j){
	    for (i=1;i<j;++i){
	    	if (check(i,j)==0){
		    	number[s][0]=i;number[s][1]=j;
		    	++s;
		    }
		}
	}
	bubble(s);
	number[s][0]=1;number[s][1]=1;
	cout<<0<<"/"<<1<<endl;
	for (i=0;i<=s;++i){
		cout<<number[i][0]<<"/"<<number[i][1]<<endl;
	}
	return 0;
}

int check(int a,int b){
	for (int i=2;i<=a;++i){
		if (a%i==0 && b%i==0){
			return 1;
		}
	}
	return 0;
}

void bubble(int s){
	int tmp1,tmp2;bool flag;
	for (int i=1;i<s;++i){
		for (int j=0;j<s-i;++j){
			flag=false;
			if (number[j][0]*number[j+1][1]
			>number[j+1][0]*number[j][1]){
				tmp1=number[j][0];number[j][0]=number[j+1][0];number[j+1][0]=tmp1;
				tmp2=number[j][1];number[j][1]=number[j+1][1];number[j+1][1]=tmp2;
				flag=true;
			}
			if (flag=false) break;
		}
	}
} 
