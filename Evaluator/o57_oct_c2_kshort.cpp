#include<bits/stdc++.h>
#define t3 tuple<int,int,int>
#define t4 tuple<int,int,int,int>

using namespace std;

int n,m,s,l;
vector<t3> g[10005];
long long dis[10005][55];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s >> l;
    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w,0});
    }
    for(int i=0,u,v,w;i<s;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w,1});
    }

    for(int i=2;i<=n;i++)
        for(int j=0;j<=50;j++)
            dis[i][j]=INT_MAX;

    priority_queue<t3,vector<t3>,greater<t3>> pq;
    pq.push({0,1,0});

    while(!pq.empty()){
        auto [du,u,used]=pq.top();
        pq.pop();

        if(dis[u][used]!=du)
            continue;

        for(auto [v,w,t]:g[u]){
            if(dis[v][used+t]>du+w){
                dis[v][used+t]=du+w;
                pq.push({du+w,v,used+t});
            }
        }
    }

    long long ans=INT_MAX;
    for(int i=0;i<=l;i++){
        ans=min(ans,dis[n][i]);
    }
    cout << ans;
}
