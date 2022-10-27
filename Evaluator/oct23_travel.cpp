#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> g[30005];
int dp[30005][16],lv[30005];

void dfs(int u,int p,int l){
    dp[u][0]=p;
    lv[u]=l;
    for(auto v:g[u]){
        if(v==p)
            continue;
        dfs(v,u,l+1);
    }
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=15;i>=0;i--){
        if(lv[dp[a][i]]>=lv[b])
            a=dp[a][i];
    }
    if(a==b)
        return a;
    for(int i=15;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,a,b;i<n-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,1,0);
    for(int j=1;j<=15;j++)
        for(int i=1;i<=n;i++)
            dp[i][j]=dp[dp[i][j-1]][j-1];

    int q,x,last=0,ans=0;
    cin >> q;
    while(q--){
        cin >> x;
        if(last){
            int l=lca(x,last);
            ans+=lv[x]-lv[l]+lv[last]-lv[l];
        }
        last=x;
    }
    cout << ans;
}
