#include <iostream>
using namespace std;

int main(){
    int K[10000]={0};
    int n,i,ans = 0;
    cin>>n;
    for (i=1;i<=n-1;++i){
        cin>>K[i];
    }
    for (i=2;i<=n;++i){   
        ans = (ans+K[n-i+1]) % i;      
    }    
    cout<<ans+1;
    return 0;
}
