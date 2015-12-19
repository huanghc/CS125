#include<iostream>
using namespace std;  
int num[10]={6,2,5,5,4,5,6,3,7,6};   
int count(int tmp);

int main(){  
    int n,i,j,a,b,c,d;  
    int p=0;
    cin>>n;  
    for(i=0;i<=1000;++i){  
       for(j=0;j<=1000;++j){  
           c=count(i);
		   b=count(j);            
		   a=count(i+j);  
           d=n-3-c-b;  
           if(d==a){  
                ++p;  //cout<<i<<"+"<<j<<"="<<a<<"  "<<d<<endl;
           }  
       }  
    }  
    cout<<p;  
    return 0;  
}  

int count(int tmp){  
    int ans=0,ret;  
    if(tmp==0) return 6;  
    while(tmp>0){  
        ret=tmp%10;  
        ans+= num[ret];  
        tmp/=10;  
    }  
    return ans;  
}  


