#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[100005];
int indeg[100005];
bitset<100005> vis(0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
            q.push(i);
    }
    if(q.empty()){
        cout << "no";
        return 0;
    }
    vector<int> v;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        if(vis[u])
            continue;
        vis[u]=1;
        v.push_back(u);

        for(auto v:g[u]){
            if(vis[v])
                continue;
            indeg[v]--;
            if(!indeg[v])
              q.push(v);
        }
    }

    if(v.size()<n)
      cout << "no";
    else
      for(int i=0;i<n;i++)
        cout << v[i] << '\n';
}
