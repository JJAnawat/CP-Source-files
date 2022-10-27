#include<bits/stdc++.h>

using namespace std;

int m,n;
vector<tuple<int,int,int>> edge;
long long sum=0;
int pa[200005];

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

void sol(){
    for(int i=0;i<m;i++)
        pa[i]=i;
    sum=0;

    edge.clear();
    for(int i=0,x,y,z;i<n;i++){
        cin >> x >> y >> z;
        sum+=z;
        edge.push_back({z,x,y});
    }

    sort(edge.begin(),edge.end());

    for(auto [w,u,v]:edge){
        u=fi(u);
        v=fi(v);
        if(u!=v){
            sum-=w;
            pa[u]=v;
        }
    }
    cout << sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> m >> n;
        if(m==0&&n==0)
            break;
        sol();
        cout << '\n';
    }
}
