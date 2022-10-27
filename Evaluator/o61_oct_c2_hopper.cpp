#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n,m;
pair<int,int> ar[3005];
int dp[3005];

bool chk(int mid){
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(ar[i].fi==ar[j].fi)
                continue;
            int dis=(ar[i].se-ar[j].se+n)%n;
            if(dis>mid)
                continue;
            dp[i]=max(dp[i],dp[j]+1);
        }
        if(dp[i]>=m+1)
            return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ar[i].first;
        ar[i].second=i;
    }
    sort(ar+1,ar+1+n);

    int l=1,r=3000;
    while(l<r){
        int mid=((l+r)>>1);
        if(chk(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout << l;
}
