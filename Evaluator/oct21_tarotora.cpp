#include<bits/stdc++.h>

using namespace std;

const int MX=1e9;
int n,k;
int a[100005],b[100005];
int dp[100005][205];

void sol(){
    cin >> n >> k;

    for(int j=0;j<=k+k;j++)
        dp[0][j]=MX;
    dp[0][k]=0;

    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k+k;j++){
            dp[i][j]=MX;
            if(j-1>=0)
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i]);
            if(j+1<=k+k)
                dp[i][j]=min(dp[i][j],dp[i-1][j+1]+b[i]);
        }
    }

    int ans=MX;
    for(int j=0;j<=k+k;j++){
        ans=min(ans,dp[n][j]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        sol();
        cout << "\n";
    }
}
