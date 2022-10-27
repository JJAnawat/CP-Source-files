#include<bits/stdc++.h>

using namespace std;

int n;
int dp[1005],ar[1005];
vector<int> v[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> ar[i];

    int ans=INT_MIN;
    vector<int> vans;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(ar[j]<ar[i]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                v[i]=v[j];
            }
        }
        v[i].push_back(ar[i]);
        if(dp[i]>ans){
            ans=dp[i];
            vans=v[i];
        }
    }
    cout << ans << '\n';
    for(auto it:vans)
        cout << it << ' ';
}
