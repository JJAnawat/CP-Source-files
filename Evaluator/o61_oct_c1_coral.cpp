#include<bits/stdc++.h>

using namespace std;

struct node{
    bool fs=0,fa=0;
};

node seg[(1<<21)];
int n,M;

void upd(int l,int r,int i,int x,int y){
    if(seg[i].fa)
        return;
    if(x>r||y<l)
        return;
    if(l==r&&l==x&&r==y){
        seg[i].fa=1;
        seg[i].fs=1;
        return;
    }
    int m=(l+r)/2;
    if(l==x&&r==y){
        if(seg[i].fs)
            return;
        seg[i].fs=1;
        if(/*l!=r && */ seg[i].fs && (seg[2*i].fs||seg[2*i+1].fs) && !(seg[2*i].fs&&seg[2*i+1].fs)){
            if(seg[2*i+1].fs)
                upd(l,m,2*i,x,m);
            else
                upd(m+1,r,2*i+1,m+1,y);
        }
        /*
        else if(l==r)
            seg[i].fa=1;
        */
    }
    if(l==r)
        return;
    upd(l,m,2*i,x,y);
    upd(m+1,r,2*i+1,x,y);
    if(seg[2*i].fs&&seg[2*i+1].fs)
        seg[i].fs=1;
    if(seg[i].fs&&seg[2*i].fs&&!seg[2*i+1].fs)
        upd(m+1,r,2*i+1,m+1,r);
    if(seg[i].fs&&!seg[2*i].fs&&seg[2*i+1].fs)
        upd(l,m,2*i,l,m);
    if(seg[2*i].fa&&seg[2*i+1].fa)
        seg[i].fa=1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> M;
    n=(1<<n);
    int ans=-1;
    for(int i=1,a,b,t;i<=M;i++){
        cin >> a >> b;
        if(ans!=-1)
            continue;
        t=a;
        a=b;
        b=b+(1<<t)-1;
        upd(0,n-1,1,a,b);
        if(seg[1].fa)
            ans=i;
    }
    cout << ans;
}
