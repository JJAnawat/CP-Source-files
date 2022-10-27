#include<bits/stdc++.h>

using namespace std;

//double log2=logl(2);
long long n,m;
unordered_map<long long,long long> ump;
vector<tuple<long long,long long,long long>> edge;
long long pa[100005];

long long fi(long long i){
    if(pa[i]==i)
        return i;
    return fi(pa[i]);
}

void sol(){
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
        pa[i]=i;
    edge.clear();
    long long a,b,c;
    for(long long i=0;i<m;i++){
        cin >> a >> b >> c;
        c=ump[c];
        edge.push_back({c,a,b});
    }
    sort(edge.begin(),edge.end());
    long long sum=0;
    for(auto [w,u,v]:edge){
        u=fi(u);
        v=fi(v);
        if(u!=v){
            sum+=w;
            pa[u]=v;
        }
    }
    cout << sum+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tmp=2,i=1;
    while(tmp<1e18){
        ump[tmp]=i;
        tmp*=2;
        i++;
    }

    int tc;
    cin >> tc;
    while(tc--){
        sol();
        cout << "\n";
    }
}
