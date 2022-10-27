#include<bits/stdc++.h>

using namespace std;

const int mod=2009;
int dp[105][105][25];
int op[25][25];
int k,n,ar[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            cin >> op[i][j];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        dp[i][i][ar[i]]=1;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i+l-1<n;i++){
            int j=i+l-1;
            for(int m=i;m+1<=j;m++){
                for(int a=0;a<k;a++){
                    for(int b=0;b<k;b++){
                        if(dp[i][m][a]&&dp[m+1][j][b]){
                            dp[i][j][op[a][b]]=(dp[i][j][op[a][b]]+dp[i][m][a]*dp[m+1][j][b])%mod;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << dp[0][n-1][i] << "\n";
    }
}

