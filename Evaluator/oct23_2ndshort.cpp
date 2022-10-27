#include<bits/stdc++.h>

using namespace std;

const int inf=2e9;
int n,m,st,ed;
vector<pair<int,int>> g[10005],rg[10005];
bitset<10005> vis(0);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int dis[10005];
queue<int> q;
int ans=inf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> st >> ed;
    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        rg[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        dis[i]=inf;
    dis[st]=0;
    pq.push({0,st});
    while(!pq.empty()){
        auto [du,u]=pq.top();
        pq.pop();

        if(vis[u])
            continue;
        vis[u]=1;

        for(auto [v,w]:g[u]){
            if(vis[v])
                continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }

    vis=0;
    q.push(ed);
    vis[ed]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto [v,w]:rg[u]){
            if(dis[v]+w>dis[u])
                ans=min(ans,dis[v]+w-dis[u]);
            else{
                if(vis[v])
                    continue;
                vis[v]=1;
                q.push(v);
            }
        }
    }

    cout << dis[ed]+ans;
}
