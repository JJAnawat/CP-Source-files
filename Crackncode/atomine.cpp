#include<bits/stdc++.h>

using namespace std;

int n,q;
vector<int> g[100005],chd[100005];
int nad[100005],p[100005],st[100005];

void upd(int u){
    st[u]*=-1;
    for(auto v:chd[u])
        upd(v);
}

int qr(int u){
    int ans=1;
    while(u!=0){
        ans*=st[u];
        u=p[u];
    }
    return ans;
}

void dfs(int u,int d,int pa){
    nad[d]=u;
    p[u]=nad[d-(d&-d)];
    for(int i=0;d-(1<<i)>d-(d&-d);i++)
        chd[nad[d-(1<<i)]].push_back(u);
    for(auto v:g[u]){
        if(v!=pa)
            dfs(v,d+1,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
        st[i]=1;

    dfs(1,1,0);

    int op,u;
    while(q--){
        cin >> op >> u;
        if(op==1){
            upd(u);
        }else{
            cout << (qr(u)==-1) << '\n';
        }
    }

}
