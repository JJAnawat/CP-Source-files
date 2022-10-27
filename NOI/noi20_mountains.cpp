#include<bits/stdc++.h>

using namespace std;

const int MXN=3e5+5;
long long n;
long long ar[MXN],pre[MXN],pos[MXN];
vector<long long> v;
unordered_map<long long,int> ump;
long long fw[2][MXN];

void upd(int o,int x){
    for(;x<MXN;x+=x&-x)
        fw[o][x]++;
}

long long qr(int o,int x){
    long long sum=0;
    for(;x>0;x-=x&-x)
        sum+=fw[o][x];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        v.push_back(ar[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=v.size();i++){
        ump[v[i-1]]=i;
    }
    for(int i=1;i<=n;i++){
        ar[i]=ump[ar[i]];
        pre[i]=qr(0,ar[i]-1);
        upd(0,ar[i]);
    }
    for(int i=n;i>=1;i--){
        pos[i]=qr(1,ar[i]-1);
        upd(1,ar[i]);
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=(pre[i]*pos[i]);
    }
    cout << ans;
}
