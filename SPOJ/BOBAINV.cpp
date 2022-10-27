#include<bits/stdc++.h>

using namespace std;

int n,q,l,r;
int ar[5005],dp[5005][5005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> ar[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<j&&ar[i]>ar[j])
                dp[i][j]=1;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << dp[r][r]-dp[l-1][r]-dp[r][l-1]+dp[l-1][l-1] << "\n";
    }
}
