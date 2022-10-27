#include<bits/stdc++.h>

using namespace std;

int R,C,M;
int seg[305][(1<<14)],lz[305][(1<<14)];

void pushlz(int l,int r,int i,int ro){
    if(!lz[ro][i])
        return;
    seg[ro][i]=lz[ro][i];
    if(l!=r){
        lz[ro][2*i]=lz[ro][i];
        lz[ro][2*i+1]=lz[ro][i];
    }
    lz[ro][i]=0;
}

void upd(int l,int r,int i,int x,int y,int v,int ro){
    pushlz(l,r,i,ro);
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y){
        lz[ro][i]=v;
        pushlz(l,r,i,ro);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,y,v,ro);
    upd(m+1,r,2*i+1,x,y,v,ro);
    seg[ro][i]=min(seg[ro][2*i],seg[ro][2*i+1]);
}

int qr(int l,int r,int i,int x,int y,int ro){
    pushlz(l,r,i,ro);
    if(l>y||r<x)
        return INT_MAX;
    if(l>=x&&r<=y)
        return seg[ro][i];
    int m=(l+r)/2;
    return min(qr(l,m,2*i,x,y,ro),qr(m+1,r,2*i+1,x,y,ro));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;
    int op,r,c,x;
    while(M--){
        cin >> op;
        if(op==1){
            cin >> r >> c >> x;
            upd(1,C,1,c,c,x,r);
        }else if(op==2){
            cin >> r >> x;
            upd(1,C,1,1,C,x,r);
        }else if(op==3){
            cin >> r >> c;
            cout << qr(1,C,1,c,c,r) << '\n';
        }else{
            int ans=INT_MAX;
            for(int r=1;r<=R;r++){
                ans=min(ans,seg[r][1]);
            }
            cout << ans << "\n";
        }
    }
}
