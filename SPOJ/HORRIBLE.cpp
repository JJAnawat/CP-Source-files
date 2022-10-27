#include<bits/stdc++.h>

using namespace std;

int n,c;
long long seg[1<<18],lz[1<<18];

void pushlz(int l,int r,int i){
    if(!lz[i])
        return;
    seg[i]+=lz[i]*(r-l+1);
    if(l!=r){
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}

void upd(int l,int r,int i,int x,int y,int v){
    pushlz(l,r,i);
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y){
        lz[i]+=v;
        pushlz(l,r,i);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,y,v);
    upd(m+1,r,2*i+1,x,y,v);
    seg[i]=seg[2*i]+seg[2*i+1];
}

long long qr(int l,int r,int i,int x,int y){
    pushlz(l,r,i);
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return qr(l,m,2*i,x,y)+qr(m+1,r,2*i+1,x,y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        memset(seg,0,sizeof(seg));
        memset(lz,0,sizeof(lz));
        cin >> n >> c;
        int op,p,q,v;
        while(c--){
            cin >> op >> p >> q;
            if(op==0){
                cin >> v;
                upd(1,n,1,p,q,v);
            }
            else{
                cout << qr(1,n,1,p,q) << "\n";
            }
        }
        /*
        for(int i=1;i<=n;i++){
            cout << qr(1,n,1,i,i) << ' ';
        }*/
    }
}

//0 26 26 126 114 94 94 80
//80
//
