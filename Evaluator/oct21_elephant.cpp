#include<bits/stdc++.h>

using namespace std;

int n;
long long ar[100005],dp[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> ar[i];

    long long ans=INT_MIN;
    for(int i=1;i<=n;i++){
        if(i<3)
            continue;
        for(int j=i-6;j<=i-3;j++)
            if(j>=0)
                dp[i]=max(dp[i],dp[j]);
        dp[i]+=ar[i];
        ans=max(ans,dp[i]);
    }
    cout << ans;
}
