#include<bits/stdc++.h>

using namespace std;

struct node{
    int mn=INT_MAX,mx=INT_MIN;
}tmpnode;

int n,k;
int ar[100005];
node seg[1<<18];

node mer(node ln,node rn){
    node tmp;
    tmp.mn=min(ln.mn,rn.mn);
    tmp.mx=max(ln.mx,rn.mx);
    return tmp;
}

void build(int l,int r,int i){
    if(l==r){
        seg[i].mx=seg[i].mn=ar[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=mer(seg[2*i],seg[2*i+1]);
}

void upd(int l,int r,int i,int x,int v){
    if(l>x||r<x)
        return;
    if(l==r){
        seg[i].mn=seg[i].mx=v;
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,v);
    upd(m+1,r,2*i+1,x,v);
    seg[i]=mer(seg[2*i],seg[2*i+1]);
}

node qr(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return tmpnode;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return mer(qr(l,m,2*i,x,y),qr(m+1,r,2*i+1,x,y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<100000;i++)
        ar[i]=i;

    cin >> n >> k;

    build(0,n-1,1);

    int op,a,b;
    while(k--){
        cin >> op >> a >> b;
        if(!op){
            swap(ar[a],ar[b]);
            upd(0,n-1,1,a,ar[a]);
            upd(0,n-1,1,b,ar[b]);
        }else{
            node ans=qr(0,n-1,1,a,b);
            if(ans.mn==a&&ans.mx==b)
                cout << "YES";
            else
                cout << "NO";
            cout << "\n";
        }
    }
}
