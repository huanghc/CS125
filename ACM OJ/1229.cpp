#include <iostream>
using namespace std;

int n;
string get;
bool mine[100000+10]={false};
bool have = false;

int hav(int cur){
    int res = 0;
    res += mine[cur];
    if(cur>0)
        res += mine[cur-1];
    if(cur<n-1)
        res += mine[cur+1];
    return res;
}

bool put(int cur){
    if(get[cur]=='*')
        return true;
    else
        return ('0' + hav(cur) ) <= get[cur];
}

bool Put(int cur){
    if(get[cur]=='*')
        return true;
    else
        return ('0' + hav(cur) ) == get[cur];
}

void dfs(int cur){
    if(have) return;
    if(cur<0){
        have = Put(0);
        return;
    }
    mine[cur] = true;
    if((cur == n-1 and put(cur))or (cur<n-1 and Put(cur+1)) )
        dfs(cur-1);
    if(have) return;

    mine[cur] = false;
    if((cur == n-1 and put(cur))
       or (cur<n-1 and Put(cur+1)) )
        dfs(cur-1);
    return;
}

int main(){
    cin>>n;cin>>get;
    dfs(n-1);
    int ans = 0;
    for (int i = 0; i < n; ++i){   
        if(mine[i])
            ans++;
    }
    cout<<ans<<endl;
    for (int i = 0; i < n; ++i){    
        cout<<mine[i];
    }
    return 0;
}
