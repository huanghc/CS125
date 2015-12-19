#include <iostream>
#include <math.h>
using namespace std;
bool Prime(long n);
int main(){
	long a,a1,a2;int i;
	cin >>a;
	bool flag=false;
	for (i=a/2;i>0;--i){
		if (Prime(i) && Prime(a-i)){		
			a1=i;
			a2=a-i;
			flag=true;break;
		}
	}
	if (flag) cout<<a1<<"\t"<<a2;
	else cout<<"NO";	
}

bool Prime(long n){
	int i;
	for (i=2; i<=sqrt(n);++i){	
		if (n%i==0) return false;
	}
	return true;
}
