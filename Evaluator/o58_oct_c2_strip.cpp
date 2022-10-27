#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int ans[10005];
long long fw[100005];
vector<pair<int,int>> p[100005],q[100005];

void upd(int x,int v){
    for(int i=x;i<=100000;i+=i&-i)
        fw[i]+=v;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=0,a,b,c,d;i<n;i++){
        cin >> a >> b >> c  >> d;
        a++,b++,c++,d++;
        p[a].push_back({b,1});
        p[a].push_back({d+1,-1});
        p[c+1].push_back({b,-1});
        p[c+1].push_back({d+1,1});
    }

    for(int i=1,a,b;i<=m;i++){
        cin >> a >> b;
        a++,b++;
        q[a].push_back({b,i});
    }

    for(int it=1;it<=100000;it++){
        for(auto [y,v]:p[it])
            upd(y,v);
        for(auto [y,i]:q[it])
            ans[i]=qr(y);
    }

    for(int i=1;i<=m;i++)
        cout << ans[i] << '\n';
}
