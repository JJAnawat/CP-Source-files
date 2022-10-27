#include<bits/stdc++.h>

using namespace std;

int n,m,q;
vector<int> g[100005],rg[100005];
vector<pair<int,int>> oper;
bitset<100005> cl(0);
vector<bool> ans;
bitset<100005> ab1(0),ab2(0);

/*
bitset<100005> vis(0);
bool cycle=0;

void dfs(int u,int p){
    if(vis[u])
        return;
    vis[u]=1;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(vis[v])
            cycle=1;
        else
            dfs(v,u);
    }
}
*/

void upd1(int u){
    ab1[u]=1;
    for(auto v:g[u]){
        if(cl[v])
            continue;
        if(ab1[v])
            continue;
        upd1(v);
    }
}

void upd2(int u){
    ab2[u]=1;
    for(auto v:rg[u]){
        if(cl[v])
            continue;
        if(ab2[v])
            continue;
        upd2(v);
    }
}

void dfs1(int u){
    ab1[u]=1;
    for(auto v:g[u]){
        if(cl[v])
            continue;
        if(ab1[v])
            continue;
        dfs1(v);
    }
}

void dfs2(int u){
    ab2[u]=1;
    for(auto v:rg[u]){
        if(cl[v])
            continue;
        if(ab2[v])
            continue;
        dfs2(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    //dfs(1,1);
    //assert(!cycle);

    for(int i=0,op,x;i<q;i++){
        cin >> op >> x;
        if(op==1)
            cl[x]=1;
        oper.push_back({op,x});
    }
    dfs1(1);
    dfs2(n);
    reverse(oper.begin(),oper.end());
    for(auto [op,x]:oper){
        if(op==1){
            cl[x]=0;
            /*
            for(auto v:rg[x]){
                if(ab1[v]){
                    ab1[x]=1;
                    break;
                }
            }*/
            for(auto v:g[x]){
                if(!cl[v]){
                    if(ab1[v])
                        upd1(v);
                    if(ab2[v])
                        upd2(v);
                }
            }
            /*
            for(auto v:g[x])
                if(ab2[v]){
                    ab2[x]=1;
                    break;
                }*/
            for(auto v:rg[x]){
                if(!cl[v]){
                    if(ab1[v])
                        upd1(v);
                    if(ab2[v])
                        upd2(v);
                }
            }
        }
        else{//op==2
            ans.push_back(ab1[x]&&ab2[x]);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout << it << "\n";
}
