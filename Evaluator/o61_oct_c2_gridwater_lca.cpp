#include<bits/stdc++.h>
using namespace std;
int m,n,p[160005];
vector<tuple<int,int,int>> edge,mst,nmst;
vector<pair<int,int>> g[160005];
int dp[160005][20],lv[160005],mx[160005][20];
bool cmp(tuple<int,int,int> &t1,tuple<int,int,int> &t2){
    return get<2>(t1)<get<2>(t2);
}
void dfs(int u,int p,int l,int x){
    lv[u]=l;
    dp[u][0]=p;
    mx[u][0]=x;
    for(int i=1;i<=18;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1],mx[dp[u][i-1]][i-1]);
    }
    for(auto [v,w]:g[u])
        if(v!=p&&!lv[v]&&v!=0)
            dfs(v,u,l+1,w);
}
int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    int ans=0;
    for(int i=18;i>=0;i--){
        if(lv[dp[a][i]]>=lv[b]){
            ans=max(ans,mx[a][i]);
            a=dp[a][i];
        }
    }
    if(a==b)
        return ans;
    for(int i=18;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            ans=max({ans,mx[a][i],mx[b][i]});
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return max({ans,mx[a][0],mx[b][0]});
}
int fi(int i){
    if(p[i]==i)
        return i;
    return fi(p[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i=0;i<m*n;i++)
        p[i]=i;
    /*
    2 3
    id/n=row
    id%n=col
    0 1 2
    3 4 5
    */
    for(int i=0;i<2*m-1;i++){
        int row=i/2;
        if(!(i%2)){
            for(int j=0,x;j<n-1;j++){
                cin >> x;
                edge.push_back({row*n+j,row*n+j+1,x});
            }
        }else{
            for(int j=0,x;j<n;j++){
                cin >> x;
                edge.push_back({row*n+j,(row+1)*n+j,x});
            }
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    for(auto it:edge){
        int u,v,w;
        tie(u,v,w)=it;
        int pu=fi(u),pv=fi(v);
        if(pu!=pv){
            p[pu]=pv;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }else{
            nmst.push_back(it);
        }
    }
    dfs(0,0,0,0);
    int ans=INT_MAX;
    for(auto [u,v,w]:nmst){
        //cout << w << ' ' << lca(u,v) << '\n';
        ans=min(ans,w-lca(u,v));
    }
    cout << ans;
}
