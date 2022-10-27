#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> g[10005];
int lv[10005],dp[15][10005],dis[10005];

void dfs(int u,int p,int l){
    lv[u]=l;
    dp[0][u]=p;
    for(auto [v,w]:g[u]){
        if(v==p)
            continue;
        dis[v]=dis[u]+w;
        dfs(v,u,l+1);
    }
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=14;i>=0;i--){
        if(lv[dp[i][a]]>=lv[b])
            a=dp[i][a];
    }
    if(a==b)
        return a;
    for(int i=14;i>=0;i--){
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    }

    return dp[0][a];
}

int lifting(int u,int tlv){
    //lift from u;
    for(int i=14;i>=0;i--){
        if(lv[dp[i][u]]>=tlv)
            u=dp[i][u];
    }
    return u;
}

void sol(){
    for(int i=1;i<=10000;i++)
        g[i].clear();

    cin >> n;
    for(int i=1,a,b,c;i<=n-1;i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dis[1]=0;
    dfs(1,1,0);
    for(int i=1;i<=14;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }

    string op;
    int a,b,k;
    while(1){
        cin >> op;
        if(op=="DONE")
            break;
        cin >> a >> b;
        if(op=="DIST"){
            int l=lca(a,b);
            cout << dis[a]+dis[b]-2*dis[l] << "\n";
        }
        else{
            cin >> k;
            int l=lca(a,b);
            int lvl=lv[a]-lv[l]+1;
            if(lvl==k)
                cout << l;
            else if(lvl>k){
                //traverse left
                cout << lifting(a,lv[a]-k+1);
            }
            else{
                //traverse right
                cout << lifting(b,lv[l]+k-lvl);
            }
            cout << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        sol();
        cout << "\n";
    }
}

/*
1
6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
DIST 4 6
KTH 4 6 4
DONE
*/
