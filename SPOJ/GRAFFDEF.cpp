#include<bits/stdc++.h>

using namespace std;

long long n,m;
vector<int> g[100005];
int disc[100005],low[100005];
int idx=0;
bitset<100005> vis(0);
map<pair<int,int>,bool> isbd;
long long cnt[100005];

void dfs(int u,int p=-1){
    vis[u]=1;
    low[u]=disc[u]=idx++;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
                isbd[{u,v}]=isbd[{v,u}]=1;
        }
        else if(v!=p)
            low[u]=min(low[u],disc[v]);
    }
}

void counting(int u,int p=-1){
    vis[u]=1;
    cnt[idx]++;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(!vis[v]&&!isbd[{u,v}])
            counting(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    vis=0;
    idx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            idx++;
            counting(i);
        }
    }
    long long wr=0;
    for(int i=1;i<=idx;i++){
        if(cnt[i]){
            wr+=(cnt[i]*(cnt[i]-1))/2;
        }
    }
    //cout << wr << '\n';
    cout << fixed << setprecision(5) << (1.0-1.0*wr/((n*(n-1))/2));
}
