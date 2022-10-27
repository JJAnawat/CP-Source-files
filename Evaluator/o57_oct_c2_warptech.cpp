#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int n,m,q;
int pa[5005];
vector<tuple<int,int,int>> edge;
int ansi[5005];
int ans[5005];

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1,a,b,c;i<=m;i++){
        cin >> a >> b >> c;
        edge.push_back({c,a,b});
    }
    sort(edge.begin(),edge.end());
    ans[0]=get<0>(edge[0]);
    ansi[0]=-n;
    for(int i=1;i<=m;i++){
        auto [w,u,v]=edge[i-1];
        u=fi(u);
        v=fi(v);
        ans[i]=ans[i-1];
        ansi[i]=ansi[i-1];
        if(u!=v){
            pa[u]=v;
            ans[i]=w;
            ansi[i]=ansi[i-1]+1;
        }
    }
    int x;
    while(q--){
        cin >> x;
        auto it=lower_bound(ansi,ansi+n+1,-x)-ansi;
        cout << ans[it] << '\n';
    }
}
/*
5 6 4
0 1 20
0 2 10
2 3 30
1 3 10
2 4 40
3 4 50
1
2
3
4
*/
