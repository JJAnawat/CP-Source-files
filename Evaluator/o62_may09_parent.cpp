#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<tuple<int,int,int>> oper;
vector<int> g[100005];
int dp[20][100005],lv[100005],pa[100005];

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

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
    for(int i=18;i>=0;i--)
        if(lv[dp[i][a]]>=lv[b])
            a=dp[i][a];
    if(a==b)
        return a;
    for(int i=18;i>=0;i--)
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    return dp[0][a];
}

int dist(int i,int j){
    int k=lca(i,j);
    return lv[i]+lv[j]-2*lv[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int op,u,v;
    for(int i=0;i<m;i++){
        cin >> op >> u;
        if(op==2)
            v=0;
        else{
            cin >> v;
            if(op==1){
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        oper.push_back({op,u,v});
    }

    for(int i=1;i<=n;i++){
        if(!lv[i])
            dfs(i,i,0);
        pa[i]=i;
    }
    for(int i=1;i<=18;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][dp[i-1][j]];

    for(auto [op,u,v]:oper){
        if(op==1){
            u=fi(u);
            v=fi(v);
            pa[u]=v;
        }
        else if(op==2){
            v=fi(u);
            pa[v]=u;
            pa[u]=u;
        }
        else if(op==3){
            int master=fi(u);
            if(dist(u,master)>dist(v,master)){
                cout << v << "\n";
            }
            else{
                cout << u << "\n";
            }
        }
    }
}
