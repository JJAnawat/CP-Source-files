#include<bits/stdc++.h>

using namespace std;

const long long MX=1e18;
int n,k;
long long dp[3005][3005],ar[3005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> ar[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=MX;

    for(int i=2;i<=k;i++)
        for(int j=i-1;j>=1;j--)
            dp[j][i]=ar[j]+ar[i];

    long long mn;
    for(int i=2;i<=n;i++){
        mn=MX;
        for(int j=i+k;j>i;j--){
            if(j-k<i&&j-k>=1){
                mn=min(mn,dp[j-k][i]);
                dp[i][j]=min(dp[i][j],mn+ar[j]);
            }
        }
    }

    long long ans=MX;
    for(int i=n-k+1;i<n;i++){
        for(int j=i+1;j<=n;j++)
            ans=min(ans,dp[i][j]);
    }
    cout << ans;
}
