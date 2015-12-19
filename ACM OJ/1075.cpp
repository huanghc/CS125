#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
	int num[4000]={0};

	num[0]=1;
	num[1]=1;
	num[2]=2;
	num[3]=4;
	for (int i =4 ;i <=n;i++){	
		num[i]=num[i-1];
		for (int j =0;j<i-1;j++)
		{
			num[i]+=num[i-2-j]*num[j];
			num[i]=num[i]%19301;
		}
	}
	cout<<num[n];

	return 0;
}
