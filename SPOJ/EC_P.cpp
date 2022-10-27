#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[705];
bitset<705> vis(0);
int disc[705],low[705];
int idx=0;
set<pair<int,int>> bd;

void dfs(int u,int p=-1){
    vis[u]=1;
    low[u]=disc[u]=idx++;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
                bd.insert({min(u,v),max(u,v)});
        }
        else if(v!=p)
            low[u]=min(low[u],disc[v]);
    }
}

void sol(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        g[i].clear();
    vis=0;
    bd.clear();
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);

    if(bd.empty())
        cout << "Sin bloqueos\n";
    else{
        cout << bd.size() << '\n';
        for(auto [u,v]:bd)
            cout << u << ' ' << v << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int i=1;i<=tc;i++){
        cout << "Caso #" << i << '\n';
        sol();
    }
}
