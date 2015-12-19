#include <cstdio>
#include <cstring>
long long a=1000000007;
long long tmmp[20];
long long l,r,k,b[20],bt,yy;

struct node {
    long long s,n;
};

node dp[20][400];

node dfs(long long pos,long long target,long long limit)
{
    node t;
    t.s=t.n=0;
    if (pos==0) {              
        if (target==100)
        t.n=1;
        return t;
    }
    if ((limit==0)&&(dp[pos][target].n!=-1)) return dp[pos][target];
    long long tail=limit?b[pos]:9;
    long long sgn=((yy-pos)%2)?(-1):(1);
    long long head;
    if (pos==yy)head =1;
    else head=0;
    for (int i=head;i<=tail;i++)
    {
        node tmp=dfs(pos-1,target-i*sgn,(limit==1)&&(i==b[pos]));
        if ((tmp.n)>0){
            t.n+=tmp.n;
            long long q;
            q=((((tmp.n%a)*tmmp[pos])%a)*i)%a;
            t.s+=(tmp.s)%a;
            t.s%=a;
            t.s+=q;
            t.s%=a;
        }
    }
    if (limit==0) dp[pos][target]=t;
    return t;
}

long long cal(long long x,long long y)
{
    long long ans=0;
    if (x==-1) return 0;
    if (x==0) return 0;
    bt = 0;
    while (x)
    {
        bt++;
        b[bt]=x%10;
        x/=10;
    }
    for (yy=1;yy<=bt;yy++){
        memset(dp,-1,sizeof dp);
        ans+=dfs(yy,y+100,yy==bt).s;
        ans=(ans+a)%a;
    }
    return ans;
}

int main()
{
    tmmp[1]=1;
    for (int i=2;i<=19;i++)
        tmmp[i]=(tmmp[i-1]*10)%a;
    scanf("%lld%lld%lld",&l,&r,&k);
    {
        printf("%lld",(cal(r,k)-cal(l-1,k)+a)%a);
    }
    return 0;
}

