#include<bits/stdc++.h>

using namespace std;

long long n,m,k;
vector<tuple<long long,long long,long long>> g[50005];
bitset<50005> vis(0);
vector<long long> dis(50005,INT_MAX);

bool sol(int mid){
    dis[1]=0;
    for(int i=2;i<=n;i++)
        dis[i]=INT_MAX;
    vis=0;
    priority_queue<pair<long long ,long long>,vector<pair<long long ,long long>>,greater<pair<long long ,long long>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [du,u]=pq.top();
        pq.pop();

        if(vis[u])
            continue;
        vis[u]=1;
        if(u==n)
            return du<=k;

        for(auto [v,c,i]:g[u]){
            if(vis[v]||i>mid)
                continue;
            if(dis[v]>du+c){
                dis[v]=du+c;
                pq.push({du+c,v});
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1,a,b,c;i<=m;i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c,i});
        g[b].push_back({a,c,i});
    }

    int l=1,r=m+1;
    while(l<r){
        int mid=((l+r)>>1);
        if(sol(mid))
            r=mid;
        else
            l=mid+1;
    }

    if(l==m+1)
        l=-1;
    cout << l;
}
