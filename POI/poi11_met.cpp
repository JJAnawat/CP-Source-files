#include<bits/stdc++.h>

using namespace std;

const int MXN=300005;
int n,m,k;
int target[MXN],L[MXN],R[MXN];
vector<int> child[MXN];
vector<tuple<int,int,int>> shower;
long long fw[MXN];
vector<int> ask[MXN];

void upd(int x,int val){
    for(int i=x;i<=300000;i+=i&-i)
        fw[i]+=val;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>=1;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1,x;i<=m;i++){
        cin >> x;
        child[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin >> target[i];
    cin >> k;
    for(int i=1,x,y,z;i<=k;i++){
        cin >> x >> y >> z;
        shower.push_back({x,y,z});
    }
    for(int i=1;i<=n;i++){
        L[i]=1;
        R[i]=k+1;
    }
    while(1){
        bool done=1;
        for(int i=1;i<=n;i++){
            if(L[i]<R[i]){
                done=0;
                ask[(L[i]+R[i])/2].push_back(i);
            }
        }
        if(done)
            break;
        memset(fw,0,sizeof(fw));
        for(int i=1;i<=k;i++){
            auto [l,r,a]=shower[i-1];
            if(l<=r){
                upd(l,a);
                upd(r+1,-a);
            }
            else{
                upd(l,a);
                upd(1,a);
                upd(r+1,-a);
            }

            for(auto it:ask[i]){
                long long sum=0;
                for(auto iit:child[it]){
                    sum+=qr(iit);
                    if(sum>=target[it])
                        break;
                }
                if(sum>=target[it])
                    R[it]=i;
                else
                    L[it]=i+1;
            }
            ask[i].clear();
        }
    }
    for(int i=1;i<=n;i++){
        if(L[i]<=k)
            cout << L[i] << "\n";
        else
            cout << "NIE\n";
    }
}
