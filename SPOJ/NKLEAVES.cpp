#include<bits/stdc++.h>

using namespace std;

int n,m;
const long long inf=1e18;
vector<long long> dp_prev(100005),dp_now(100005);
long long ar[100005];
long long ipf[100005],pf[100005];

long long cost(int i,int j){
    return ipf[j]-ipf[i-1]-(pf[j]-pf[i-1])*i;
}

void compute(int l,int r,int opl,int opr){
    if(l>r)
        return;
    int m=(l+r)/2;
    dp_now[m]=inf;
    int opk;
    for(int k=opl;k<=min(opr,m);k++){
        if(dp_now[m]>dp_prev[k]+cost(k+1,m)){
            dp_now[m]=dp_prev[k]+cost(k+1,m);
            opk=k;
        }
    }
    compute(l,m-1,opl,opk);
    compute(m+1,r,opk,opr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        pf[i]=pf[i-1]+ar[i];
        ipf[i]=ipf[i-1]+ar[i]*i;
        dp_prev[i]=cost(1,i);
    }

    for(int i=2;i<=m;i++){
        compute(1,n,1,n);
        dp_prev=dp_now;
    }

    cout << dp_prev[n];
}
