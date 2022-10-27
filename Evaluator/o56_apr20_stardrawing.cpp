#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[100005];
int deg[100005],cnt=0;
bitset<100005> vis(0);
int deg3=0;
bool cycle=0;
bool sz[3][100005];
set<tuple<int,int,int>> s3;
set<tuple<int,int>> s4;

void dfs(int u,int p){
    vis[u]=1;
    cnt++;
    if(deg[u]==3)
        deg3=u;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(vis[v]){
            cycle=1;
            continue;
        }
        dfs(v,u);
    }
}

void dfs2(int u,int p){
    //cout << u << ' ';
    cnt++;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(v==deg3)
            continue;
        dfs2(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int tmp[3];
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            deg3=0;
            cycle=0;
            cnt=0;
            dfs(i,0);
            if(!deg3){
                if(!cycle)
                    sz[1][cnt]=1;
                else
                    sz[2][cnt]=1;
            }
            else{
                if(!cycle){
                    for(int i=0;i<3;i++){
                        cnt=0;
                        dfs2(g[deg3][i],deg3);
                        tmp[i]=cnt;
                    }
                    sort(tmp,tmp+3);
                    tuple<int,int,int> tp={tmp[0],tmp[1],tmp[2]};
                    s3.insert(tp);
                }else{
                    for(int i=0;i<3;i++){
                        cnt=0;
                        dfs2(g[deg3][i],deg3);
                        tmp[i]=cnt;
                        //cout << '\n';
                        //cout << g[deg3][i] << ' ' << cnt << "\n";
                    }
                    sort(tmp,tmp+3);
                    tuple<int,int> tp;
                    if(tmp[0]==tmp[1]){
                        tp={tmp[1],tmp[2]};
                    }else{
                        tp={tmp[1],tmp[0]};
                    }
                    //cout << get<0>(tp) << ' ' << get<1>(tp) << '\n';
                    s4.insert(tp);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            ans+=sz[i][j];
        }
    }
    cout << ans+s3.size()+s4.size();
}

/*
12 12
1 2
2 3
3 4
1 4
1 5
5 6
7 8
8 9
7 9
7 10
10 11
11 12

*/
