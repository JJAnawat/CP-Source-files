#include<bits/stdc++.h>

using namespace std;

int n,m;
string ar[3005];
int dp[3005][3005][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        ar[i]=" "+ar[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]=='G'){
                if(i-1>=1&&i+1<=n&&ar[i-1][j]=='R'&&ar[i+1][j]=='W'){
                    dp[i][j][1]=max(dp[i-1][j+1][1],dp[i-1][j+1][0])+1;
                }
                if(j-1>=1&&j+1<=m&&ar[i][j-1]=='R'&&ar[i][j+1]=='W'){
                    dp[i][j][2]=max(dp[i-1][j+1][2],dp[i-1][j+1][0])+1;
                }
            }
            dp[i][j][0]=max({dp[i-1][j+1][0],dp[i-1][j+1][1],dp[i-1][j+1][2]});
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=max({dp[i][1][0],dp[i][1][1],dp[i][1][2]});
    }
    for(int j=2;j<=m;j++){
        ans+=max({dp[n][j][0],dp[n][j][1],dp[n][j][2]});
    }
    cout << ans << '\n';
}
