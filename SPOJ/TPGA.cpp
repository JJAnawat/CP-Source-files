#include<bits/stdc++.h>

using namespace std;

const long long mod=1e9+7;

long long fact[200005];
long long fw[200005],n;

void upd(long long x){
    for(long long i=x;i<=200000;i+=i&-i)
        fw[i]=fw[i]+1;
}

long long qr(long long x){
    long long sum=0;
    for(long long i=x;i>=1;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    for(long long i=1;i<=200000;i++){
        fact[i]=(i%mod*fact[i-1]%mod)%mod;
    }

    long long tc,ans=1;
    cin >> tc;
    while(tc--){
        ans=1;
        memset(fw,0,sizeof(fw));
        cin >> n;
        for(long long i=1,x;i<=n;i++){
            cin >> x;
            if(i!=n){
                upd(x);
                x=x-qr(x-1);
                ans=(ans%mod+((x-1)%mod*fact[n-i]%mod))%mod;
            }
        }
        cout << ans << '\n';
    }

}
