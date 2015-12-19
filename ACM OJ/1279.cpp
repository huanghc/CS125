#include<iostream>
#include<algorithm>
#include<stdio.h> 
#include<cstring>
using namespace std;

int num[100010];
int value(char a){
    if(a>='0'&&a<='9') return a-'0';
	if (a == 'A' || a == 'B' || a == 'C')  return 2; 
	if (a == 'D' || a == 'E' || a == 'F')  return 3;  
	if (a == 'G' || a == 'H' || a == 'I')  return 4;   
	if (a == 'J' || a == 'K' || a == 'L')  return 5;   
	if (a == 'M' || a == 'N' || a == 'O')  return 6;   
	if (a == 'P' || a == 'R' || a == 'S')  return 7;  
	if (a == 'T' || a == 'U' || a == 'V')  return 8;  
	if (a == 'W' || a == 'X' || a == 'Y')  return 9;   
}

int main(){
    int n,i,j;cin>>n;
    for(i=0; i<n; i++){
        char s[205];
        cin>>s;
        int len=strlen(s);
        for(j=0; j<len; j++){      
            if(s[j]=='-') continue;
            num[i]= value(s[j])+num[i]*10;
        }
    }
    sort(num,num+n);
    bool flag=true;
    for(i=0; i<n; i++){
        int tmp=1;
        while(num[i]==num[i+1] && i+1<n){ 
			i++;tmp++;
			flag=false;
		}
        if(tmp>=2){
        	printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,tmp);
        }
    }
    if(flag) cout<<"No duplicates.\n";
    return 0;
}
