#include<bits/stdc++.h>

using namespace std;

int n,k;
int dp[10005][(1<<7)];
int ar[(1<<7)];
int ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0;i<(1<<k);i++){
        cin >> ar[i];
        dp[k][i]=ar[i];
        ans=max(ans,ar[i]);
    }

    for(int i=k+1;i<=n;i++){
        for(int j=0;j<(1<<k);j++){
            dp[i][j]=ar[j]+max(dp[i-1][j/2],dp[i-1][j/2+(1<<(k-1))]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans;
}
