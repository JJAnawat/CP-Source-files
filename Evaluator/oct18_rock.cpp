#include<bits/stdc++.h>

using namespace std;

long long n,ar[105];
long long dp[55][55];

long long sol(int l,int r){
    if(l>r)
        return 0;
    if(l==r)
        return ar[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    long long ul=ar[l]+max(sol(l+2,r),sol(l+1,r-1));
    long long ur=ar[r]+max(sol(l,r-2),sol(l+1,r-1));
    return dp[l][r]=max(ul,ur);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=2*n;i++)
        cin >> ar[i];
    cout << sol(1,2*n);
}
