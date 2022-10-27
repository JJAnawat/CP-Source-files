#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int>> g[100005];
int pa[100005],lv[100005],upe[100005];
multiset<int> pool;
vector<tuple<int,int,int>> ledge;

void dfs(int u,int p,int l,int x){
    pa[u]=p;
    lv[u]=l;
    upe[u]=x;
    for(auto [v,w]:g[u]){
        if(v==p)
            continue;
        dfs(v,u,l+1,w);
    }
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    int ans=INT_MIN;
    while(lv[a]!=lv[b]){
        ans=max(ans,upe[a]);
        a=pa[a];
    }
    if(a==b)
        return ans;
    while(a!=b){
        ans=max({ans,upe[a],upe[b]});
        a=pa[a];
        b=pa[b];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,a,b,c;i<n-1;i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for(int i=n-1,a,b,c;i<m;i++){
        cin >> a >> b >> c;
        ledge.push_back({a,b,c});
        pool.insert(c);
    }
    dfs(1,1,1,0);
    vector<int> ans;
    for(auto [a,b,c]:ledge){
        int mx=lca(a,b);
        auto it=pool.upper_bound(mx);
        if(it==pool.end()){
            cout << 0;
            return 0;
        }
        ans.push_back(*it);
        pool.erase(it);
    }
    cout << 1 << '\n';
    for(auto it:ans)
        cout << it << '\n';
}
