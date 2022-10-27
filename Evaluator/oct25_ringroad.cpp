#include<bits/stdc++.h>

using namespace std;

int n,k,q;
long long fw[200005];
int pa[200005],di[200005];

void upd(int x,int v){
    for(int i=x;i<=200000;i+=i&-i)
        fw[i]+=v;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}

long long dis(int a,int b){
    return abs(di[a]-di[b]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> q;
    for(int i=1,x;i<=k;i++){
        cin >> x;
        upd(i,x);
        pa[i]=i;
        di[i]=0;
    }

    for(int i=k+1,a,b;i<=n;i++){
        cin >> a >> b;
        pa[i]=pa[a];
        di[i]=di[a]+b;
    }

    int op,a,b;
    while(q--){
        cin >> op >> a >> b;
        if(!op){
            long long tmp=qr(a)-qr(a-1);
            upd(a,b-tmp);
        }else{
            if(pa[a]==pa[b]){
                cout << dis(a,b) << '\n';
            }else{
                long long di1=dis(a,pa[a]),di2=dis(b,pa[b]);
                a=pa[a];
                b=pa[b];
                if(a<b)
                    swap(a,b);
                long long tmp=qr(a-1)-qr(b-1);
                long long di3=min(qr(k)-tmp,tmp);
                cout << di1+di2+di3 << '\n';
            }
        }
    }
}

/*
6 3 5
1
1
1
1 2
3 3
4 2
1 2 5
1 5 6
0 3 10
1 4 5
1 2 1
*/
