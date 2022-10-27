#include<bits/stdc++.h>

using namespace std;

int n,m,l,q;
vector<pair<int,long long>> g[80005];
int pot[80005];
long long dis[80005][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> l >> q;
    for(int i=0,u,v;i<m;i++){
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    for(int i=1,x;i<=l;i++){
        cin >> x;
        pot[x]=i;
    }

    for(int i=1;i<=n;i++)
        for(int j=0;j<=q;j++)
            dis[i][j]=LLONG_MAX;

    priority_queue<tuple<long long,int,int,int>,vector<tuple<long long,int,int,int>>,greater<tuple<long long,int,int,int>>> pq;
    dis[1][0]=0;
    pq.push({0,1,0,0});
    while(!pq.empty()){
        auto [du,u,st,prev]=pq.top();
        pq.pop();

        if(du!=dis[u][st])
            continue;

        bool can=0;
        if(pot[u]&&st+1<=q&&pot[u]!=prev)
            can=1;
        for(auto [v,w]:g[u]){
            if(dis[v][st]>dis[u][st]+(w>>st)){
                dis[v][st]=dis[u][st]+(w>>st);
                pq.push({dis[v][st],v,st,prev});
            }
            if(can){
                int nst=st+1;
                if(dis[v][nst]>dis[u][st]+(w>>nst)){
                    dis[v][nst]=dis[u][st]+(w>>nst);
                    pq.push({dis[v][nst],v,nst,pot[u]});
                }
            }
        }
    }

    long long ans=LLONG_MAX;
    for(int i=q;i>=0;i--){
        ans=min(ans,dis[n][i]);
    }
    cout << ans;
}
