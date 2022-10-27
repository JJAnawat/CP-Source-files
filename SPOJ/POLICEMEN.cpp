#include<bits/stdc++.h>

using namespace std;

int n,q;
vector<int> g[10005];
int lv[10005],dp[15][10005];

void dfs(int u,int p,int l){
    lv[u]=l;
    dp[0][u]=p;
    for(auto v:g[u]){
        if(v==p)
            continue;
        dfs(v,u,l+1);
    }
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=14;i>=0;i--){
        if(lv[dp[i][a]]>=lv[b])
            a=dp[i][a];
    }
    if(a==b)
        return a;
    for(int i=14;i>=0;i--){
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    }
    return dp[0][a];
}

int dist(int a,int b){
    return lv[a]-lv[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1,a,b;i<=n-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,1,0);
    for(int i=1;i<=14;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }

    cin >> q;
    int a,b;
    while(q--){
        cin >> a >> b;
        int l=lca(a,b);
        //cout << l << "\n";
        if(dist(a,l)>=dist(b,l)){
            cout << "YES " << l << "\n";
        }
        else{
            cout << "NO\n";
        }

    }
}
