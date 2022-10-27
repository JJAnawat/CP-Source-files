#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[10005];
set<int> ap;
bitset<10005> vis(0);
int idx=0;
int disc[10005],low[10005];

void dfs(int u,int p=-1){
    vis[u]=1;
    low[u]=disc[u]=idx++;
    int ch=0;
    for(auto v:g[u]){
        if(!vis[v]){
            ch++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if((p!=-1&&low[v]>=disc[u])||(p==-1&&ch>1))
                ap.insert(u);
        }
        else if(v!=p)
            low[u]=min(low[u],disc[v]);
    }
}

void sol(){
    ap.clear();
    for(int i=0;i<=n;i++)
        g[i].clear();
    vis=0;
    idx=0;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ap.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> n >> m;
        if(!n&&!m)
            break;
        sol();
    }
}
