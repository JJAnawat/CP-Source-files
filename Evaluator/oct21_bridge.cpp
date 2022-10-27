#include<bits/stdc++.h>

using namespace std;

int n,a[3005],b[3005];
int dp[3005][3005];

int sol(int l,int r){
    if(l<=0||r<=0)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(a[l]==b[r])
        return dp[l][r]=max(dp[l][r],1+sol(l-1,r-1));
    int nr=r;
    while(nr!=0&&a[l]!=b[nr])
        nr--;
    return dp[l][r]=max(1+sol(l,nr-1),sol(l-1,r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> b[i];
    cout << sol(n,n);
}
