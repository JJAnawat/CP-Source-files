#include<bits/stdc++.h>

using namespace std;

const long long mod=1e9-1;
int n,k;
long long ar[80005],dp[45][80005];
long long fw[45][80005];

void upd(int id,int x,int v){
    for(int i=x;i<=80000;i+=i&-i)
        fw[id][i]+=v;
}

long long qr(int id,int x){
    long long sum=0;
    for(int i=x;i>=1;i-=i&-i)
        sum+=fw[id][i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for(int j=n;j>=1;j--){
        for(int i=1;i<=k;i++){
            if(i==1)
                dp[i][j]=1;
            else
                dp[i][j]=qr(i-1,ar[j]-1)%mod;
            upd(i,ar[j],dp[i][j]);
        }
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        //cout << dp[k][i] << " ";
        ans=(ans+dp[k][i])%mod;
    }
    cout << ans;
}
