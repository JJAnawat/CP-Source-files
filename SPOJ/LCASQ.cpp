#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> g[10005];
int lv[10005],dp[10005][15];

void dfs(int u,int p=0,int l=0){
    lv[u]=l;
    dp[u][0]=p;
    for(auto v:g[u])
        if(v!=p)
            dfs(v,u,l+1);
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=14;i>=0;i--){
        if(lv[dp[a][i]]>=lv[b])
            a=dp[a][i];
    }
    if(a==b)
        return a;
    for(int i=14;i>=0;i--){
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
    for(int i=0,sz;i<n;i++){
        cin >> sz;
        for(int j=0,x;j<sz;j++){
            cin >> x;
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }

    dfs(0);
    for(int i=1;i<=14;i++){
        for(int j=0;j<n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }

    int q;
    cin >> q;
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }
}
