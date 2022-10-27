#include<bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int cl[100005];
queue<int> q;

bool bfs(int u){
    while(!q.empty())
        q.pop();
    cl[u]=1;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto v:g[u]){
            if(!cl[v]){
                cl[v]=3-cl[u];
                q.push(v);
            }else if(cl[v]==cl[u])
                return 0;
        }
    }
    return 1;
}

void sol(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        g[i].clear();
        cl[i]=0;
    }
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(cl[i])
            continue;
        if(!bfs(i)){
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        sol();
    }
}
