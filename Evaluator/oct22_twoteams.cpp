#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[100005];
vector<pair<int,int>> edge;
int cl[100005];
queue<int> q;

bool chk(int mid){
    for(int i=1;i<=n;i++)
        g[i].clear();
    memset(cl,0,sizeof(cl));
    for(int i=1;i<=mid;i++){
        auto [u,v]=edge[i];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while(!q.empty())
        q.pop();
    for(int i=1;i<=n;i++){
        if(!cl[i]){
            cl[i]=1;
            q.push(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(auto v:g[u]){
                    if(!cl[v]){
                        cl[v]=3-cl[u];
                        q.push(v);
                    }
                    else if(cl[v]!=3-cl[u])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    edge.push_back({0,0});
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        edge.push_back({u,v});
    }

    if(chk(m-1))
        cout << m-1;
    else
        cout << m;
    /*
    int l=1,r=m;
    while(l<r){
        int mid=l+(r-l)/2;
        if(chk(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout << l;*/
}
