#include<bits/stdc++.h>

using namespace std;

int n,m,pa[1005];
vector<tuple<double,int,int,int>> edge;
double ans=0;

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

int main(){
    ios_base::sync_with_stdio(false);;
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        pa[i]=i;
    double w;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v >> w;
        edge.push_back({w,u,v,i});
    }
    sort(edge.begin(),edge.end());
    vector<int> vt;
    for(auto [w,u,v,i]:edge){
        u=fi(u);
        v=fi(v);
        if(u!=v){
            ans+=w;
            pa[u]=v;
            vt.push_back(i);
        }
    }
    sort(vt.begin(),vt.end());
    cout << ans << '\n';
    for(auto it:vt)
        cout << it << '\n';
}
